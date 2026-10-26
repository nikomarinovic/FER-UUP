#define _POSIX_C_SOURCE 199309L

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BANNER_WIDTH 94
#define SLOT_MAX_MULTIPLIER 50

static const char *const separator =
    "==============================================================================================";

typedef struct {
    const char *name;
    const char *color;
    int multiplier;
    int weight;
} slot_symbol;

static const slot_symbol slot_symbols[] = {
    {"CHERRY", "\033[1;31m", 2, 30}, {"LEMON", "\033[1;33m", 3, 25},
    {"ORANGE", "\033[1;35m", 4, 20}, {"PLUM", "\033[1;34m", 6, 15},
    {"BELL", "\033[1;33m", 10, 7},   {"DIAMOND", "\033[1;36m", 20, 2},
    {"SEVEN", "\033[1;31m", 50, 1},
};

static void print_centered(const char *text) {
    size_t width = 0;

    for (const unsigned char *character = (const unsigned char *)text; *character; character++) {
        if ((*character & 0xC0) != 0x80) {
            width++;
        }
    }

    size_t padding = width < BANNER_WIDTH ? (BANNER_WIDTH - width) / 2 : 0;
    printf("%*s%s\n", (int)padding, "", text);
}

static void show_game_screen(const char *title, const char *subtitle, const char *color, long long balance) {
    puts("");
    puts(separator);
    printf("%s", color);
    print_centered(title);
    printf("\033[0m");
    puts(separator);
    puts("");
    print_centered(subtitle);
    printf("                                  Current balance: %lld EUR\n", balance);
    puts("");
    puts(separator);
}

static int read_integer(const char *prompt, int *value) {
    int input_character;
    int result;

    printf("%s", prompt);
    result = scanf("%d", value);
    while ((input_character = getchar()) != '\n' && input_character != EOF) {
    }

    if (result == EOF || input_character == EOF) {
        return 0;
    }
    return result == 1 ? 1 : -1;
}

static void wait_for_game_exit(void) {
    int choice;

    puts("Gameplay is coming soon.");
    puts("Enter 0 to return to the game selection menu.");
    for (;;) {
        int input_status = read_integer("Your choice: ", &choice);

        if (input_status == 0 || choice == 0) {
            return;
        }
        if (input_status < 0) {
            printf("\033[1;31mPlease enter 0 to return to the menu.\033[0m\n");
        }
    }
}

static int read_amount(const char *prompt, long long *amount) {
    int input_character;
    int result;

    printf("%s", prompt);
    result = scanf("%lld", amount);
    while ((input_character = getchar()) != '\n' && input_character != EOF) {
    }

    if (result == EOF || input_character == EOF) {
        return 0;
    }
    return result == 1 ? 1 : -1;
}

static void print_dice_summary_row(const char *label, long long amount) {
    printf("| %-15s %10lld EUR%11s|\n", label, amount, "");
}

static void print_dice_result_details(int guess, int roll) {
    printf("| %-15s %-25s|\n", "Your guess:", guess == 1 ? "LOW (1-3)" : "HIGH (4-6)");
    printf("| %-15s %-25d|\n", "Dice roll:", roll);
}

static void animate_dice_roll(void) {
    static const char *const dice_faces[] = {"\342\232\200", "\342\232\201", "\342\232\202",
                                             "\342\232\203", "\342\232\204", "\342\232\205"};
    const struct timespec frame_delay = {0, 100000000L};

    printf("\n\033[1;36mRolling the dice ");
    fflush(stdout);
    for (int frame = 0; frame < 20; frame++) {
        printf("\r\033[2K\033[1;36mRolling the dice  [ %s ]\033[0m", dice_faces[rand() % 6]);
        fflush(stdout);
        nanosleep(&frame_delay, NULL);
    }
    puts("\n");
}

static void play_blackjack(void) {
    wait_for_game_exit();
}

static void play_roulette(void) {
    wait_for_game_exit();
}

static int spin_slot_reel(void) {
    int ticket = rand() % 100;

    for (size_t i = 0; i < sizeof(slot_symbols) / sizeof(slot_symbols[0]); i++) {
        if (ticket < slot_symbols[i].weight) {
            return (int)i;
        }
        ticket -= slot_symbols[i].weight;
    }

    return (int)(sizeof(slot_symbols) / sizeof(slot_symbols[0])) - 1;
}

static void print_slot_symbol(int symbol) {
    printf("%s%-11s\033[0m", slot_symbols[symbol].color, slot_symbols[symbol].name);
}

static void print_slot_status(const char *status, const char *color) {
    size_t padding = (58 - strlen(status)) / 2;

    printf("\033[2K       ║%*s%s%s%*s\033[0m║\n",
           (int)padding, "", color, status, (int)(58 - padding - strlen(status)), "");
}

static void print_slot_animation_frame(const int reels[3], const int stopped[3]) {
    printf("\033[2K       ╔══════════════════════════════════════════════════════════╗\n");
    printf("\033[2K       ║                    \033[1;35m✦  FER JACKPOT  ✦\033[0m                     ║\n");
    printf("\033[2K       ║    ┌─────────────┐   ┌─────────────┐   ┌─────────────┐   ║\n");
    printf("\033[2K       ║    │ ");
    print_slot_symbol((reels[0] + 1) % (int)(sizeof(slot_symbols) / sizeof(slot_symbols[0])));
    printf(" │   │ ");
    print_slot_symbol((reels[1] + 1) % (int)(sizeof(slot_symbols) / sizeof(slot_symbols[0])));
    printf(" │   │ ");
    print_slot_symbol((reels[2] + 1) % (int)(sizeof(slot_symbols) / sizeof(slot_symbols[0])));
    printf(" │   ║\n");
    printf("\033[2K       ║    │ ");
    for (int reel = 0; reel < 3; reel++) {
        if (stopped[reel]) {
            printf("\033[1;32m");
        } else {
            printf("\033[1;33m");
        }
        printf("%-11s\033[0m │", slot_symbols[reels[reel]].name);
        if (reel < 2) {
            printf("   │ ");
        }
    }
    printf("   ║\n");
    printf("\033[2K       ║    │ ");
    print_slot_symbol((reels[0] + 2) % (int)(sizeof(slot_symbols) / sizeof(slot_symbols[0])));
    printf(" │   │ ");
    print_slot_symbol((reels[1] + 2) % (int)(sizeof(slot_symbols) / sizeof(slot_symbols[0])));
    printf(" │   │ ");
    print_slot_symbol((reels[2] + 2) % (int)(sizeof(slot_symbols) / sizeof(slot_symbols[0])));
    printf(" │   ║\n");
    printf("\033[2K       ║    └─────────────┘   └─────────────┘   └─────────────┘   ║\n");
    if (stopped[2]) {
        print_slot_status("ALL REELS LOCKED", "\033[1;32m");
    } else if (stopped[1]) {
        print_slot_status("REELS 1-2 LOCKED  REEL 3 SPINNING", "\033[1;36m");
    } else if (stopped[0]) {
        print_slot_status("REEL 1 LOCKED  REELS 2-3 SPINNING", "\033[1;36m");
    } else {
        print_slot_status("SPINNING...", "\033[1;36m");
    }
    printf("\033[2K       ╚══════════════════════════════════════════════════════════╝\n");
}

static void animate_slot_spin(int reels[3]) {
    static const struct timespec frame_delay = {0, 85000000L};
    const int stop_frame[3] = {17, 27, 37};
    int current[3] = {spin_slot_reel(), spin_slot_reel(), spin_slot_reel()};
    int stopped[3] = {0, 0, 0};
    int next_tick[3] = {0, 0, 0};

    for (int frame = 0; frame <= stop_frame[2]; frame++) {
        if (frame > 0) {
            printf("\033[9A");
        }
        for (int reel = 0; reel < 3; reel++) {
            if (!stopped[reel]) {
                if (frame >= stop_frame[reel]) {
                    current[reel] = reels[reel];
                    stopped[reel] = 1;
                } else if (frame >= next_tick[reel]) {
                    current[reel] = spin_slot_reel();
                    next_tick[reel] = frame + 1 + frame / 9;
                }
            }
        }
        print_slot_animation_frame(current, stopped);
        fflush(stdout);
        nanosleep(&frame_delay, NULL);
    }
    puts("");
}

static void print_slots_paytable(void) {
    puts("\033[1;35m");
    puts("  THREE OF A KIND                 TOTAL PAYOUT");
    puts("  --------------------------------------------");
    for (size_t i = 0; i < sizeof(slot_symbols) / sizeof(slot_symbols[0]); i++) {
        printf("  ");
        print_slot_symbol((int)i);
        printf("                         %2dx bet\n", slot_symbols[i].multiplier);
    }
    puts("  Any pair: your bet back (PUSH)");
    puts("\033[0m");
    puts("  Payout multipliers include your original bet.");
    puts("  Enter 0 as your bet to return to the game selection menu.");
}

static void play_slots(long long *balance) {
    long long bet;
    long long winnings;
    int reels[3];

    if (*balance == 0) {
        puts("\033[1;31mYou're out of credits. Return to the menu and try another game.\033[0m");
        return;
    }

    print_slots_paytable();
    for (;;) {
        int input_status;
        long long maximum_bet = (LLONG_MAX - *balance) / (SLOT_MAX_MULTIPLIER - 1);

        printf("\n\033[1;33mBalance: %lld EUR\033[0m\n", *balance);
        input_status = read_amount("Your bet (0 to return): ", &bet);
        if (input_status == 0 || (input_status == 1 && bet == 0)) {
            return;
        }
        if (input_status < 0 || bet < 0 || bet > *balance || bet > maximum_bet) {
            printf("\033[1;31mInvalid bet. Enter an amount from 1 to your balance, or 0 to return.\033[0m\n");
            continue;
        }
        for (int i = 0; i < 3; i++) {
            reels[i] = spin_slot_reel();
        }
        animate_slot_spin(reels);
        *balance -= bet;

        if (reels[0] == reels[1] && reels[1] == reels[2]) {
            winnings = bet * slot_symbols[reels[0]].multiplier;
            *balance += winnings;
            printf("\033[1;32m  JACKPOT! Three %s! You won %lld EUR.\033[0m\n",
                   slot_symbols[reels[0]].name, winnings);
        } else if (reels[0] == reels[1] || reels[0] == reels[2] || reels[1] == reels[2]) {
            winnings = bet;
            *balance += winnings;
            printf("\033[1;33m  NICE! A pair — your %lld EUR bet is back.\033[0m\n", winnings);
        } else {
            winnings = 0;
            printf("\033[1;31m  No match this time. You lost %lld EUR.\033[0m\n", bet);
        }
        printf("  Bet: %lld EUR   |   Payout: %lld EUR   |   New balance: %lld EUR\n",
               bet, winnings, *balance);
        if (*balance == 0) {
            puts("\033[1;31mYou're out of credits. Return to the menu and try another game.\033[0m");
            return;
        }
    }
}

static void play_poker(void) {
    wait_for_game_exit();
}

static void play_dice(long long *balance) {
    long long bet;
    long long winnings;
    int roll;
    int guess;
    int input_status;

    puts("Guess LOW (1-3) or HIGH (4-6). A correct guess pays 2x your bet.");
    puts("Enter 0 as your bet to return to the game selection menu.");
    for (;;) {
        printf("\n\033[1;33mBalance: %lld EUR\033[0m\n", *balance);
        input_status = read_amount("Your bet (0 to return): ", &bet);
        if (input_status == 0 || (input_status == 1 && bet == 0)) {
            return;
        }
        if (input_status < 0 || bet < 0 || bet > *balance || bet > LLONG_MAX - *balance) {
            printf("\033[1;31mInvalid bet. Enter an amount from 1 to your balance, or 0 to return.\033[0m\n");
            continue;
        }

        for (;;) {
            input_status = read_integer("Guess: 1 = LOW (1-3), 2 = HIGH (4-6): ", &guess);
            if (input_status == 0) {
                return;
            }
            if (input_status == 1 && (guess == 1 || guess == 2)) {
                break;
            }
            printf("\033[1;31mInvalid guess. Enter 1 for LOW or 2 for HIGH.\033[0m\n");
        }

        animate_dice_roll();
        roll = rand() % 6 + 1;
        *balance -= bet;

        if ((guess == 1 && roll <= 3) || (guess == 2 && roll >= 4)) {
            winnings = bet * 2;
            *balance += winnings;

            puts("\n\033[1;32m+------------------------------------------+");
            puts("|                 YOU WIN!                 |");
            puts("+------------------------------------------+");
            print_dice_result_details(guess, roll);
            puts("+------------------------------------------+");
            print_dice_summary_row("Your bet:", bet);
            print_dice_summary_row("Your winnings:", winnings);
            print_dice_summary_row("Balance:", *balance);
            puts("+------------------------------------------+\033[0m");
        } else {
            winnings = 0;

            puts("\n\033[1;31m+------------------------------------------+");
            puts("|            I'M SORRY, YOU LOST           |");
            puts("+------------------------------------------+");
            print_dice_result_details(guess, roll);
            puts("+------------------------------------------+");
            print_dice_summary_row("Your bet:", bet);
            print_dice_summary_row("Your winnings:", winnings);
            print_dice_summary_row("Balance:", *balance);
            puts("+------------------------------------------+\033[0m");
        }
    }
}

int main(void) {
    int choice;
    long long balance = 1000;

    srand((unsigned int)time(NULL));

    puts(separator);
    printf("\033[1;35m");
    puts("$$$$$$$$\\ $$$$$$$$\\ $$$$$$$\\         $$$$$$\\   $$$$$$\\   $$$$$$\\  $$$$$$\\ $$\\   $$\\  $$$$$$\\");
    puts("$$  _____|$$  _____|$$  __$$\\       $$  __$$\\ $$  __$$\\ $$  __$$\\ \\_$$  _|$$$\\  $$ |$$  __$$\\");
    puts("$$ |      $$ |      $$ |  $$ |      $$ /  \\__|$$ /  $$ |$$ /  \\__|  $$ |  $$$$\\ $$ |$$ /  $$ |");
    puts("$$$$$\\    $$$$$\\    $$$$$$$  |      $$ |      $$$$$$$$ |\\$$$$$$\\    $$ |  $$ $$\\$$ |$$ |  $$ |");
    puts("$$  __|   $$  __|   $$  __$$<       $$ |      $$  __$$ | \\____$$\\   $$ |  $$ \\$$$$ |$$ |  $$ |");
    puts("$$ |      $$ |      $$ |  $$ |      $$ |  $$\\ $$ |  $$ |$$\\   $$ |  $$ |  $$ |\\$$$ |$$ |  $$ |");
    puts("$$ |      $$$$$$$$\\ $$ |  $$ |      \\$$$$$$  |$$ |  $$ |\\$$$$$$  |$$$$$$\\ $$ | \\$$ | $$$$$$  |");
    puts("\\__|      \\________|\\__|  \\__|       \\______/ \\__|  \\__| \\______/ \\______|\\__|  \\__| \\______/");
    printf("\033[0m");
    puts(separator);

    puts("");
    printf("\033[1;36m");
    print_centered("WELCOME TO FER CASINO");
    printf("\033[0m");
    puts("");
    print_centered("Good luck, have fun, and enjoy the game!");
    printf("\033[90m");
    puts("");
    print_centered("Developed by nikomarinovic");
    printf("\033[0m");
    puts("");
    puts(separator);

    puts("");
    printf("\033[1;32m");
    print_centered("CHOOSE A GAME TO PLAY");
    printf("\033[0m");
    puts("");
    puts("    1. Blackjack");
    puts("    2. Roulette");
    puts("    3. Slots");
    puts("    4. Poker");
    puts("    5. Dice");
    puts("");

    for (;;) {
        printf("\033[1;33mBalance: %lld EUR\033[0m\n", balance);
        puts("");
        printf("\033[1;36mChoose a game (0 to exit): \033[0m");
        int input_status = read_integer("", &choice);
        if (input_status == 0) {
            printf("\033[1;32m\nGoodbye!\033[0m\n");
            return 0;
        }
        if (input_status < 0) {
            printf("\033[1;31mInvalid input. Please enter a number from 0 to 5.\033[0m\n");
            continue;
        }

        switch (choice) {
        case 1:
            show_game_screen("BLACKJACK", "Hit the table and aim for 21.", "\033[1;33m", balance);
            play_blackjack();
            break;
        case 2:
            show_game_screen("ROULETTE", "Place your bets and let the wheel spin.", "\033[1;31m", balance);
            play_roulette();
            break;
        case 3:
            show_game_screen("SLOTS", "Spin the reels and try your luck.", "\033[1;35m", balance);
            play_slots(&balance);
            break;
        case 4:
            show_game_screen("POKER", "Read the table. Play your hand.", "\033[1;36m", balance);
            play_poker();
            break;
        case 5:
            show_game_screen("DICE", "Roll the dice and see where they land.", "\033[1;32m", balance);
            play_dice(&balance);
            break;
        case 0:
            printf("\033[1;32mThanks for visiting FER Casino. Goodbye!\033[0m\n");
            return 0;
        default:
            printf("\033[1;31mInvalid choice. Please choose a game from 1 to 5, or enter 0 to exit.\033[0m\n");
            break;
        }
    }
}
