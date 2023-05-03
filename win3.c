#include "project.h"
int main()
{
    system("clear");
    system("figlet -w 125% -c -r -f Univers \"Welcome To\" | lolcat");
    system("figlet -w 90% -c -r -f Univers \" Demo\" | lolcat");
    system("figlet -w 120% -c -r -f Univers \"Banking\" | lolcat");
    sleep(1);
    system("clear");
    fram(); 
    printf("\n\n\n\n\n\n\n\n\n");
    system("figlet -w 145% -c  -f starwars \"Thank    You\" | lolcat");
    printf("\n\n\n\t\t\t");
    system("echo \"                    I am honored to be standing before you today to present my banking project.Thank you for your attention!\" | pv -qL 10");  //add mv
    printf("\n\n\n");
    system("figlet -w 110% -c -r -f Univers \"The end\" | lolcat");
    printf("\n\n\n\n\n");
    return 0;
}

void fram()
{
    int ch, flag = 0;
    int x, y;
    initscr();
    noecho();
    curs_set(0);
    cbreak();
    getmaxyx(stdscr, y, x);
    clear();
    refresh();
    WINDOW *win1, *win2;
    win1 = newwin(y, (x / 2) - 1, 0, 1);
    win2 = newwin(y, (x / 2) - 1, 0, x / 2);
    wrefresh(win1);
    wrefresh(win2);

    start_color();
    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    wbkgdset(win1, COLOR_PAIR(1));
    wbkgdset(win2, COLOR_PAIR(1));

    keypad(win1, TRUE);
    showmenu(win1);
    while (1)
    {
        ch = wgetch(win1);
        switch (ch)
        {
        case KEY_UP:

            if (ligt == 1)
            {
                ligt = 4;
            }
            else
                ligt--;
            break;
        case KEY_DOWN:

            if (ligt == 4)
            {
                ligt = 1;
            }
            else
                ligt++;
            break;
        case ENTER:
            flag = ligt;
            break;
        }
        showmenu(win1);
        if (flag == 1)
        {
            keypad(win1, FALSE);
            curs_set(1);
            admin(win2);
            wrefresh(win2);
        }
        else if (flag == 2)
        {
            keypad(win1, FALSE);
            curs_set(1);
            maneger(win2);
            wrefresh(win2);
        }
        else if (flag == 3)
        {
            keypad(win1, FALSE);
            curs_set(1);
            customer(win2);
            wrefresh(win2);
        }
        else if (flag == 4)
        {
            break;
        }
        keypad(win1, TRUE);
        curs_set(0);
        flag = 0;
    }

    refresh();
    clrtoeol();
    endwin();
}

void showmenu(WINDOW *win)
{
    int x = 26, y = 15;
    wclear(win);
    box(win, 0, 0);
    wrefresh(win);
    for (int i = 0; i < 4; i++)
    {
        if (ligt == i + 1)
        {
            wattron(win, A_REVERSE);
            mvwprintw(win, y, x, "%s", menu[i]);
            wattroff(win, A_REVERSE);
        }
        else
        {
            mvwprintw(win, y, x, "%s", menu[i]);
        }
        y++;
    }
    wrefresh(win);
}
void admin(WINDOW *win2)
{
    wclear(win2);
    box(win2, 0, 0);
    char ch = ' ';
    mvwprintw(win2, 14, 30, "Admin Login");
    mvwprintw(win2, 16, 24, "Enter Your username :");
    echo();
    mvwscanw(win2, 16, 46, "%s", admn.usr);
    mvwprintw(win2, 17, 22, "Enter Your Password :");
    noecho();
    int i = 0;
    while (ch != '\n' && i < 16)
    {
        wrefresh(win2);
        ch = getch();
        admn.password[i++] = ch;
        mvwprintw(win2, 17, 42 + i, "*");
    }
    admn.password[i - 1] = '\0';

    int n = PassCheck(1, admn.usr, admn.password);
    if (n == 1)
    {
        workmenu(win2, 1);
    }
    else if (n == 2)
    {
        mvwprintw(win2, 19, 26, " Invalid password");
    }
    else if (n == 3)
    {
        mvwprintw(win2, 19, 26, " Invalid usename");
    }
    wrefresh(win2);
}
void maneger(WINDOW *win2)
{
    wclear(win2);
    box(win2, 0, 0);
    char ch = ' ';
    mvwprintw(win2, 14, 30, "Maneger Login");
    mvwprintw(win2, 16, 24, "Enter Your username :");
    echo();
    mvwscanw(win2, 16, 46, "%s", manegr.usr);
    mvwprintw(win2, 17, 22, "Enter Your Password :");
    noecho();
    int i = 0;
    while (ch != '\n' && i < 16)
    {
        wrefresh(win2);
        ch = getch();
        manegr.password[i++] = ch;
        mvwprintw(win2, 17, 42 + i, "*");
    }
    manegr.password[i - 1] = '\0';
    int n = PassCheck(2, manegr.usr, manegr.password);
    if (n == 1)
    {
        workmenu(win2, 2);
    }
    else if (n == 2)
    {
        mvwprintw(win2, 19, 26, " Invalid password");
    }
    else if (n == 3)
    {
        mvwprintw(win2, 19, 26, " Invalid usename");
    }
    wrefresh(win2);
    refresh();
}
void customer(WINDOW *win2)
{
    wclear(win2);
    box(win2, 0, 0);
    // char usr[12], pass[17],
    char ch = ' ';
    mvwprintw(win2, 14, 30, "User Login");
    mvwprintw(win2, 16, 24, "Enter Your username :");
    echo();
    mvwscanw(win2, 16, 46, "%s", customr.usr);
    mvwprintw(win2, 17, 22, "Enter Your Password :");
    noecho();
    int i = 0;
    while (ch != '\n' && i < 16)
    {
        wrefresh(win2);
        ch = getch();
        customr.password[i++] = ch;
        mvwprintw(win2, 17, 42 + i, "*");
    }
    customr.password[i - 1] = '\0';
    int n = PassCheck(3, customr.usr, customr.password);
    if (n == 1)
    {
        workmenu(win2, 3);
    }
    else if (n == 2)
    {
        mvwprintw(win2, 19, 26, " Invalid password");
    }
    else if (n == 3)
    {
        mvwprintw(win2, 19, 26, " Invalid usename");
    }
    wrefresh(win2);
}
int PassCheck(int n, char usr[12], char pass[17])
{
    FILE *flog;
    char fname[40] = "userinfo/";
    if (n == 1)
    {
        strcat(fname, "admin/");
    }
    else if (n == 2)
    {
        strcat(fname, "manager/");
    }
    else if (n == 3)
    {
        strcat(fname, "customer/password/");
    }

    char checkfile[40];
    char check[40];
    strcpy(checkfile, usr);
    strcat(fname, usr);
    strcat(checkfile, pass);
    strcat(fname, ".txt");
    flog = fopen(fname, "r");
    if (flog == NULL)
    {
        return 3; // Invalid Username
    }

    else if (!access(fname, F_OK))
    {
        fscanf(flog, "%s", check);
        fclose(flog);
        if (strcmp(check, checkfile) == 0)
        {
            return 1; // Login successfull
        }
        else
        {
            return 2; // Invalid Password
        }
    }
}
void workmenu(WINDOW *win2, int flag)
{
    if (flag == 1)
    {
        int lite = 1, ctrl = 0;
        int ch;
        cbreak();
        curs_set(0);
        keypad(win2, TRUE);
        showadminmenu(win2, lite);
        while (1)
        {
            ch = wgetch(win2);
            switch (ch)
            {
            case KEY_UP:

                if (lite == 1)
                {
                    lite = 4;
                }
                else
                    lite--;
                break;
            case KEY_DOWN:

                if (lite == 4)
                {
                    lite = 1;
                }
                else
                    lite++;
                break;
            case ENTER:
                ctrl = lite;
                break;
            }
            showadminmenu(win2, lite);

            if (ctrl == 1)
            {
                addmaneger(win2);
                ctrl = 0;
                showadminmenu(win2, lite);
            }
            else if (ctrl == 2)
            {
                deletemaneger(win2);
                ctrl = 0;
                showadminmenu(win2, lite);
            }
            else if (ctrl == 3)
            {
                accountinfo(win2);
                ctrl = 0;
                showadminmenu(win2, lite);
            }
            else if (ctrl == 4)
            {
                wclear(win2);
                return;
            }
        }
    }
    else if (flag == 2)
    {

        /*
            lite variable for control menu hilighting;
            ctrl variable for control after enter a menu.
            ch variable for input from keybord.
        */
        int lite = 1, ctrl = 0;
        int ch;
        cbreak();
        curs_set(0);
        keypad(win2, TRUE);
        showmanegermenu(win2, lite);
        while (1)
        {
            ch = wgetch(win2);
            switch (ch)
            {
            case KEY_UP:

                if (lite == 1)
                {
                    lite = 6;
                }
                else
                    lite--;
                break;
            case KEY_DOWN:

                if (lite == 6)
                {
                    lite = 1;
                }
                else
                    lite++;
                break;
            case ENTER:
                ctrl = lite;
                break;
            }
            showmanegermenu(win2, lite);

            if (ctrl == 1)
            {
                addcustomer(win2);
                ctrl = 0;
                showmanegermenu(win2, lite);
            }
            else if (ctrl == 2)
            {
                deletecustomer(win2);
                ctrl = 0;
                showmanegermenu(win2, lite);
            }
            else if (ctrl == 3)
            {
                accountinfo(win2);
                ctrl = 0;
                showmanegermenu(win2, lite);
            }
            else if (ctrl == 4)
            {
                deposit(win2);
                ctrl = 0;
                showmanegermenu(win2, lite);
            }
            else if (ctrl == 5)
            {
                withdraw(win2);
                ctrl = 0;
                showmanegermenu(win2, lite);
            }
            else if (ctrl == 6)
            {
                wclear(win2);
                return;
            }
        }
    }
    else if (flag == 3)
    {
        int lite = 1, ctrl = 0;
        int ch;
        cbreak();
        curs_set(0);
        keypad(win2, TRUE);
        showcustomermenu(win2, lite);
        while (1)
        {
            ch = wgetch(win2);
            switch (ch)
            {
            case KEY_UP:

                if (lite == 1)
                {
                    lite = 4;
                }
                else
                    lite--;
                break;
            case KEY_DOWN:

                if (lite == 4)
                {
                    lite = 1;
                }
                else
                    lite++;
                break;
            case ENTER:
                ctrl = lite;
                break;
            }
            showcustomermenu(win2, lite);

            if (ctrl == 1)
            {
                selfbalance(win2);
                ctrl = 0;
                showcustomermenu(win2, lite);
            }
            else if (ctrl == 2)
            {
                selfinfo(win2);
                ctrl = 0;
                showcustomermenu(win2, lite);
            }
            else if (ctrl == 3)
            {
                transfer(win2);
                ctrl = 0;
                showcustomermenu(win2, lite);
            }
            else if (ctrl == 4)
            {
                wclear(win2);
                return;
            }
        }
    }
}

void showadminmenu(WINDOW *win2, int lite)
{
    int x = 26, y = 15;
    wclear(win2);
    box(win2, 0, 0);
    wrefresh(win2);
    for (int i = 0; i < 4; i++)
    {
        if (lite == i + 1)
        {
            wattron(win2, A_REVERSE);
            mvwprintw(win2, y, x, "%s", adminmenu[i]);
            wattroff(win2, A_REVERSE);
        }
        else
        {
            mvwprintw(win2, y, x, "%s", adminmenu[i]);
        }
        y++;
    }
    wrefresh(win2);
}
void showmanegermenu(WINDOW *win2, int lite)
{
    int x = 26, y = 15;
    wclear(win2);
    box(win2, 0, 0);
    wrefresh(win2);
    for (int i = 0; i < 6; i++)
    {
        if (lite == i + 1)
        {
            wattron(win2, A_REVERSE);
            mvwprintw(win2, y, x, "%s", manegermenu[i]);
            wattroff(win2, A_REVERSE);
        }
        else
        {
            mvwprintw(win2, y, x, "%s", manegermenu[i]);
        }
        y++;
    }
    wrefresh(win2);
}
void showcustomermenu(WINDOW *win2, int lite)
{
    int x = 26, y = 15;
    wclear(win2);
    box(win2, 0, 0);
    wrefresh(win2);
    for (int i = 0; i < 5; i++)
    {
        if (lite == i + 1)
        {
            wattron(win2, A_REVERSE);
            mvwprintw(win2, y, x, "%s", customermenu[i]);
            wattroff(win2, A_REVERSE);
        }
        else
        {
            mvwprintw(win2, y, x, "%s", customermenu[i]);
        }
        y++;
    }
    wrefresh(win2);
}

void addmaneger(WINDOW *win2)
{
    wclear(win2);
    wrefresh(win2);
    box(win2, 0, 0);
    echo();
    curs_set(1);

    FILE *fp;

    char fname[30] = "userinfo/manager/";
    mvwprintw(win2, 15, 27, "Create Username : ");
    wscanw(win2, "%s", rmanager.name);
    strcat(fname, rmanager.name);
    strcat(fname, ".txt");

    if (!access(fname, F_OK))
    {
        wprintw(win2, "Invalid Usename\n");
        wprintw(win2, "Enter a valid username\n");
        strcpy(fname, " ");
        return;
    }
    else
    {
        fp = fopen(fname, "w");
        fputs(rmanager.name, fp);
        mvwprintw(win2, 16, 27, "Create Password: ");
        noecho();
        int i = 0;
        char ch;
        while (ch != '\n')
        {
            ch = wgetch(win2);
            rmanager.password[i++] = ch;
            wprintw(win2, "*");
        }

        fputs(rmanager.password, fp);
        fclose(fp);
        // printw("\nYour Pass is : %s", user[0].password);
    }
    curs_set(0);
}
void deletemaneger(WINDOW *win2)
{
    wclear(win2);
    echo();
    curs_set(1);
    box(win2, 0, 0);
    int check;
    char fname[30] = "userinfo/manager/";
    mvwprintw(win2, 14, 22, "Enter Your Username : ");
    wscanw(win2, "%s", rmanager.name);

    strcat(fname, rmanager.name);
    strcat(fname, ".txt");
    check = remove(fname);
    if (check == 0)
    {
        mvwprintw(win2, 16, 22, "Delete successfully");
    }
    else
    {
        mvwprintw(win2, 16, 22, "Error!! uneble to delete");
    }

    mvwprintw(win2, 18, 22, "Press any key to continue");
    wrefresh(win2);
    getch();
    noecho();
    curs_set(0);
}

void addcustomer(WINDOW *win2)
{
    wclear(win2);
    wrefresh(win2);
    box(win2, 0, 0);
    echo();
    curs_set(1);
    char fname[50] = "userinfo/customer/password/";
    FILE *fp, *fp1, *fp3;
    mvwprintw(win2, 10, 22, "Create a Username : ");
    wscanw(win2, "%s", rcustomer.usr);
    strcpy(cinfo.usr, rcustomer.usr); // chk

    strcat(fname, rcustomer.usr);
    strcat(fname, ".txt");
    fp = fopen(fname, "r");
    if (!access(fname, F_OK))
    {
        mvwprintw(win2, 17, 22, "Invalid Usename\n");
        mvwprintw(win2, 18,22,"Enter a valid username\n");

        fclose(fp);
        mvwprintw(win2, 20, 22, "Press any key to continue");
        wrefresh(win2);
        curs_set(0);
        getch();

        return;
    }
    else
    {

        mvwprintw(win2, 11, 22, "Set user Password: ");
        noecho();
        int i = 0;
        char ch;
        while (ch != '\n')
        {
            ch = wgetch(win2);
            rcustomer.password[i++] = ch;
            wprintw(win2, "*");
        }
        echo();
        mvwprintw(win2, 13, 22, "Enter Full Name : ");
        wgetstr(win2, cinfo.name);
        mvwprintw(win2, 15, 22, "Enter Account Number : ");
        wscanw(win2, "%s", cinfo.account);
        strcpy(cbalence.account, cinfo.account);

        char info[70] = "userinfo/customer/information/";
        strcat(info, cinfo.account);
        strcat(info, ".txt"); // make user info path

        char cbaln[70] = "userinfo/customer/balence/";
        strcat(cbaln, rcustomer.usr);
        strcat(cbaln, ".txt"); // make user balence path

        // fp = fopen(info, "r");
        if (!access(info, F_OK))
        {
            mvwprintw(win2, 17, 22, "Invalid Account"); // if account invaid
            mvwprintw(win2, 18, 22, "Press any key to continue");
            wrefresh(win2);
            getch();
            noecho();
            curs_set(0);
            return;
        }
        else
        {
            mvwprintw(win2, 17, 22, "Enter Initial Balance : ");
            wscanw(win2, "%d", &cbalence.balance);

            fp = fopen(fname, "a+");
            fputs(rcustomer.usr, fp); // user pass save
            fputs(rcustomer.password, fp);
            fclose(fp);

            fp1 = fopen(info, "w");
            fwrite(&cinfo, sizeof(cinfo), 1, fp1); // user info save
            fclose(fp1);

            fp3 = fopen(cbaln, "w");
            fwrite(&cbalence, sizeof(cbalence), 1, fp1); // user balance save
            fclose(fp1);
            noecho();
            curs_set(0);
            wclear(win2);
            mvwprintw(win2, 19, 22, "Succesfully create a user");
            mvwprintw(win2, 21, 22, "Press any key to continue");
            wrefresh(win2);
            getch();
        }
    }
    curs_set(0);
}
void deletecustomer(WINDOW *win2)
{
    wclear(win2);
    echo();
    curs_set(1);
    box(win2, 0, 0);

    mvwprintw(win2, 14, 22, "Enter Your Username : ");
    wscanw(win2, "%s", rcustomer.name);

    char fname[50] = "userinfo/customer/password/";
    strcat(fname, rcustomer.name); // crete password path
    strcat(fname, ".txt");

    if (access(fname, F_OK))
    {
        mvwprintw(win2, 16, 22, "Error!! Invalid user name!!"); // check username

        mvwprintw(win2, 18, 22, "Press any key to continue");
        wrefresh(win2);

        curs_set(0);
        getch();
        noecho();
        return;
    }
    else
    {
        char cbaln[70] = "userinfo/customer/balence/";
        strcat(cbaln, rcustomer.name); // crete balance path
        strcat(cbaln, ".txt");

        FILE *fp;
        fp = fopen(cbaln, "r");
        fread(&cbalence, sizeof(cbalence), 1, fp); // read user account from file
        fclose(fp);

        char info[70] = "userinfo/customer/information/";
        strcat(info, cbalence.account); // create information path
        strcat(info, ".txt");

        if ((remove(fname)) == 0 && (remove(cbaln)) == 0 && (remove(info)) == 0)
        {
            mvwprintw(win2, 16, 22, "Delete successfully");
        }
        else
        {
            mvwprintw(win2, 16, 22, "Error!! uneble to delete");
        }
        mvwprintw(win2, 18, 22, "Press any key to continue");
        wrefresh(win2);
    }

    getch();
    noecho();
    curs_set(0);
}

void accountinfo(WINDOW *win2)
{
    wclear(win2);
    box(win2, 0, 0);

    char info[70] = "userinfo/customer/information/";

    mvwprintw(win2, 15, 22, "Enter Account Number : ");
    echo();
    curs_set(1);
    wscanw(win2, "%s", cinfo.account);
    strcat(info, cinfo.account);
    strcat(info, ".txt"); // make user info path

    if (access(info, F_OK))
    {
        mvwprintw(win2, 17, 22, "Invalid Account"); // if account invaid
        mvwprintw(win2, 18, 22, "Press any key to continue");
        wrefresh(win2);
        getch();
        noecho();
        curs_set(0);
        return;
    }
    else
    {
        FILE *fp, *fp1;

        fp = fopen(info, "r");
        fread(&cinfo, sizeof(cinfo), 1, fp); // read name from file
        fclose(fp);

        char cbaln[70] = "userinfo/customer/balence/";

        strcat(cbaln, cinfo.usr);
        strcat(cbaln, ".txt"); // make user balence path

        fp1 = fopen(cbaln, "r");
        fread(&cbalence, sizeof(cbalence), 1, fp1); // read balance from file
        fclose(fp1);

        mvwprintw(win2, 17, 22, "User name : %s", cinfo.name); // if account invaid
        mvwprintw(win2, 18, 22, "User Balance : %d", cbalence.balance);
        mvwprintw(win2, 20, 22, "Enter any key to continue");
        wrefresh(win2);
        getch();
        noecho();
        curs_set(0);
    }
}

void deposit(WINDOW *win2)
{

    wclear(win2);
    box(win2, 0, 0);

    char info[70] = "userinfo/customer/information/";

    mvwprintw(win2, 15, 22, "Enter Account Number : ");
    echo();
    curs_set(1);
    wscanw(win2, "%s", cinfo.account);
    strcat(info, cinfo.account);
    strcat(info, ".txt"); // make user info path

    if (access(info, F_OK))
    {
        mvwprintw(win2, 17, 22, "Invalid Account"); // if account invaid
        mvwprintw(win2, 18, 22, "Press any key to continue");
        wrefresh(win2);
        getch();
        noecho();
        curs_set(0);
        return;
    }
    else
    {
        FILE *fp, *fp1;

        fp = fopen(info, "r");
        fread(&cinfo, sizeof(cinfo), 1, fp); // read name from file
        fclose(fp);

        char cbaln[70] = "userinfo/customer/balence/";

        strcat(cbaln, cinfo.usr);
        strcat(cbaln, ".txt"); // make user balence path

        fp1 = fopen(cbaln, "r");
        fread(&cbalence, sizeof(cbalence), 1, fp1); // read balance from file
        fclose(fp1);

        mvwprintw(win2, 17, 22, "User name : %s", cinfo.name); // if account invaid
        mvwprintw(win2, 18, 22, "User Balance : %d", cbalence.balance);
        wrefresh(win2);
    }

    char ch;
    mvwprintw(win2, 22, 22, "enter 'y' to comfirm 'N' for exit :");
    wscanw(win2, "%c", &ch);

    if (ch == 'y' || ch == 'Y')
    {
        wclear(win2);
        box(win2, 0, 0);
        int amunt;
        mvwprintw(win2, 17, 22, "Enter deposit ammount :");
        wscanw(win2, "%d", &amunt);
        amunt += cbalence.balance;
        mvwprintw(win2, 19, 22, "Updated balance is %d", amunt);

        mvwprintw(win2, 22, 22, "Enter Any key To Continue!");
        wrefresh(win2);
        getch();
        cbalence.balance = amunt; // update balance in structure

        FILE *fp;
        char cbaln[70] = "userinfo/customer/balence/";
        strcat(cbaln, cinfo.usr);
        strcat(cbaln, ".txt"); // make user balence path

        fp = fopen(cbaln, "w");
        fwrite(&cbalence, sizeof(cbalence), 1, fp); // read balance from file
        fclose(fp);
    }
    else
    {
        return;
        noecho();
        curs_set(0);
    }

    noecho();
    curs_set(0);
}
void withdraw(WINDOW *win2)
{
    wclear(win2);
    box(win2, 0, 0);

    char info[70] = "userinfo/customer/information/";

    mvwprintw(win2, 15, 22, "Enter Account Number : ");
    echo();
    curs_set(1);
    wscanw(win2, "%s", cinfo.account);
    strcat(info, cinfo.account);
    strcat(info, ".txt"); // make user info path

    if (access(info, F_OK))
    {
        mvwprintw(win2, 17, 22, "Invalid Account"); // if account invaid
        mvwprintw(win2, 18, 22, "Press any key to continue");
        wrefresh(win2);
        getch();
        noecho();
        curs_set(0);
        return;
    }
    else
    {
        FILE *fp, *fp1;

        fp = fopen(info, "r");
        fread(&cinfo, sizeof(cinfo), 1, fp); // read name from file
        fclose(fp);

        char cbaln[70] = "userinfo/customer/balence/";

        strcat(cbaln, cinfo.usr);
        strcat(cbaln, ".txt"); // make user balence path

        fp1 = fopen(cbaln, "r");
        fread(&cbalence, sizeof(cbalence), 1, fp1); // read balance from file
        fclose(fp1);

        mvwprintw(win2, 17, 22, "User name : %s", cinfo.name); // if account invaid
        mvwprintw(win2, 18, 22, "User Balance : %d", cbalence.balance);
        wrefresh(win2);
    }

    char ch;
    mvwprintw(win2, 22, 22, "enter 'y' to comfirm 'N' for exit :");
    wscanw(win2, "%c", &ch);

    if (ch == 'y' || ch == 'Y')
    {
        wclear(win2);
        box(win2, 0, 0);
        int amunt;
        mvwprintw(win2, 17, 22, "Enter Withdwawal ammount :");
        wscanw(win2, "%d", &amunt);
        amunt = cbalence.balance - amunt;
        mvwprintw(win2, 19, 22, "New Balence %d", amunt);

        mvwprintw(win2, 22, 22, "Enter Any key To Continue!");
        wrefresh(win2);
        getch();
        cbalence.balance = amunt; // update balance in structure

        FILE *fp;
        char cbaln[70] = "userinfo/customer/balence/";
        strcat(cbaln, cinfo.usr);
        strcat(cbaln, ".txt"); // make user balence path

        fp = fopen(cbaln, "w");
        fwrite(&cbalence, sizeof(cbalence), 1, fp); // read balance from file
        fclose(fp);
    }
    else
    {
        return;
        noecho();
        curs_set(0);
    }

    noecho();
    curs_set(0);
}

void selfbalance(WINDOW *win2)
{
    wclear(win2);
    box(win2, 0, 0);
    char cbaln[70] = "userinfo/customer/balence/";

    strcat(cbaln, customr.usr);
    strcat(cbaln, ".txt"); // make user balence path
    FILE *fp1;
    fp1 = fopen(cbaln, "r");
    fread(&cbalence, sizeof(cbalence), 1, fp1); // read balance from file
    fclose(fp1);
    mvwprintw(win2, 18, 22, "Your Balance is : %d", cbalence.balance);
    mvwprintw(win2, 20, 22, "Enter any key to continue");
    wrefresh(win2);
    getch();
}

void selfinfo(WINDOW *win2)
{
    wclear(win2);
    box(win2, 0, 0);
    char cbaln[70] = "userinfo/customer/balence/";

    strcat(cbaln, customr.usr);
    strcat(cbaln, ".txt"); // make user balence path
    FILE *fp1;
    fp1 = fopen(cbaln, "r");
    fread(&cbalence, sizeof(cbalence), 1, fp1); // read balance from file
    fclose(fp1);

    char info[70] = "userinfo/customer/information/"; // make info path
    strcat(info, cbalence.account);
    strcat(info, ".txt");

    fp1 = fopen(info, "r");
    fread(&cinfo, sizeof(cinfo), 1, fp1); // read balance from file
    fclose(fp1);

    mvwprintw(win2, 17, 22, "User name : %s", cinfo.name); // if account invaid
    mvwprintw(win2, 18, 22, "User Balance : %d", cbalence.balance);
    mvwprintw(win2, 20, 22, "Enter any key to continue");
    wrefresh(win2);
    getch();
}

void transfer(WINDOW *win2)
{
    int amunt, amunt2;
    FILE *fp;
    char myuser[20];
    strcpy(myuser, customr.usr);
    wclear(win2);
    box(win2, 0, 0);

    char info[70] = "userinfo/customer/information/";

    mvwprintw(win2, 15, 22, "Enter Account Number : ");
    echo();
    curs_set(1);
    wscanw(win2, "%s", cinfo.account);
    strcat(info, cinfo.account);
    strcat(info, ".txt"); // make user info path

    if (access(info, F_OK))
    {
        mvwprintw(win2, 17, 22, "Invalid Account"); // if account invaid
        mvwprintw(win2, 18, 22, "Press any key to continue");
        wrefresh(win2);
        getch();
        noecho();
        curs_set(0);
        return;
    }
    else
    {
        FILE *fp, *fp1;

        fp = fopen(info, "r");
        fread(&cinfo, sizeof(cinfo), 1, fp); // read name from file
        fclose(fp);

        char cbaln[70] = "userinfo/customer/balence/";

        strcat(cbaln, cinfo.usr);
        strcat(cbaln, ".txt"); // make user balence path

        fp1 = fopen(cbaln, "r");
        fread(&cbalence, sizeof(cbalence), 1, fp1); // read balance from file
        fclose(fp1);

        mvwprintw(win2, 17, 22, "User name : %s", cinfo.name); // if account invaid
                                                               // mvwprintw(win2, 18, 22, "User Balance : %d", cbalence.balance);
        wrefresh(win2);
    }

    char ch;
    mvwprintw(win2, 22, 22, "enter 'y' to comfirm 'N' for exit :");
    wscanw(win2, "%c", &ch);

    if (ch == 'y' || ch == 'Y')
    {
        wclear(win2);
        box(win2, 0, 0);

        mvwprintw(win2, 17, 22, "Enter Transfer ammount :");
        wscanw(win2, "%d", &amunt);
        amunt2 = amunt;
        amunt = cbalence.balance + amunt;
        mvwprintw(win2, 20, 22, "Successfully Transfer!!");
        mvwprintw(win2, 22, 22, "Enter Any key To Continue!");
        wrefresh(win2);
        getch();
        cbalence.balance = amunt; // update balance in structure

        char cbaln[70] = "userinfo/customer/balence/";
        strcat(cbaln, cinfo.usr);
        strcat(cbaln, ".txt"); // make transection balence path

        fp = fopen(cbaln, "w");
        fwrite(&cbalence, sizeof(cbalence), 1, fp); // read balance from file
        fclose(fp);
    }
    else
    {
        return;
        noecho();
        curs_set(0);
    }

    char sbaln[70] = "userinfo/customer/balence/";
    strcat(sbaln, myuser);
    strcat(sbaln, ".txt"); // make self balence path

    fp = fopen(sbaln, "r");
    fread(&cbalence, sizeof(cbalence), 1, fp);
    fclose(fp);

    cbalence.balance -= amunt2;
    fp = fopen(sbaln, "w");
    fwrite(&cbalence, sizeof(cbalence), 1, fp);
    fclose(fp);

    noecho();
    curs_set(0);
}