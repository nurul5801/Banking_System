#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdlib.h>
#define ENTER 10
#ifndef PROJECT_H
#define PROJECT_H
#endif
struct REGISTRATION
{
    char name[20];
    char usr[12];
    char password[17];

} rmanager,rcustomer;
struct login
{
    char name[20];
    char usr[12];
    char password[17];

} admn, manegr, customr;
struct Info
{
    char name[28];
    char account[11];
    char usr[12];
}cinfo;
struct Balance
{
    char account[12];
    int balance;
}cbalence;
void transfer(WINDOW *win2);
void selfbalance(WINDOW *win2);
void selfinfo(WINDOW *win2);
void deposit(WINDOW *win2);
void withdraw(WINDOW *win2);
void accountinfo(WINDOW *win2);
void addcustomer(WINDOW *win2);
void deletecustomer(WINDOW *win2);
void addmaneger(WINDOW *win2);
void deletemaneger(WINDOW *win2);
void showadminmenu(WINDOW *win2, int lite);
void showmanegermenu(WINDOW *win2, int lite);
void showcustomermenu(WINDOW *win2, int lite);
void workmenu(WINDOW *win2, int flag);
int PassCheck(int, char[12], char[17]);
void showmenu(WINDOW *win);
void admin(WINDOW *win2);
void maneger(WINDOW *win2);
void customer(WINDOW *win2);
char *menu[] = {
    "Admin",
    "Manager",
    "Customer",
    "Exit",
};
int ligt = 1;
void fram();

char *adminmenu[] = {
    " Add Maneger",
    " Delete manager",
    " Show account info",
    " exit",

};
char *manegermenu[] = {
    " Crete Account",
    " Close Account",
    " Show account info",
    " Deposit",
    " Withdraw",
    " exit",
};

char *customermenu[] = {
    " Check Balance",
    " Show account info",
    " Balance Transfer",
    " exit",
};