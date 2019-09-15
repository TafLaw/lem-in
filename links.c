/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:51:02 by txaba             #+#    #+#             */
/*   Updated: 2019/09/11 17:40:11 by txaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
t_lst *las = NULL;
t_lst *fir = NULL;

void    create_links(t_lst **p, char *da)
{
    t_lst *temp;
    t_lst *t;

    temp = (t_lst *)malloc(sizeof(t_lst));
    temp->data = ft_strdup(da);
    temp->right = NULL;
    temp->left = NULL;
    if (*p == NULL)
        *p = temp;
    else if (*p != NULL)
    {
        t = *p;
        while (t->right != NULL)
            t = t->right;
        t->right = temp;
        las = temp;
        fir = temp;
        temp->left = t;   
    }
}
void    create_path(t_lst **p, char *da)
{
    t_lst *temp;
    t_lst *t;

    temp = (t_lst *)malloc(sizeof(t_lst));
    temp->data = ft_strdup(da);
    temp->right = NULL;
    temp->left = NULL;
    if (*p == NULL)
        *p = temp;
    else if (*p != NULL)
    {
        t = *p;
        while (t->right != NULL)
            t = t->right;
        t->right = temp;
        temp->left = t;   
    }
}

size_t p_len(char *str)
{
    size_t i = 0;

    while (str[i] != '-')
        i++;
    return (i);
}

size_t s_len(char *str)
{
    size_t i = 0;
    size_t j = 0;

    while (str[i] != '-')
        i++;
    while(str[i++])
        j++;
    return (j);
}

void    single_paths(t_in **p, char *s)
{
    t_in *temp;
    t_in *t;

    temp = (t_in *)malloc(sizeof(t_in));
    temp->data = ft_strdup(s);
    temp->next = NULL;;
    if (*p == NULL)
        *p = temp;
    else if (*p != NULL)
    {
        t = *p;
        while (t->next != NULL)
            t = t->next;
        t->next = temp;   
    }
}

/* void    links(char *str, t_lst **path, t_in **res)
{
    char **pre;
    int  i;
    
    i = 0;
    pre = ft_strsplit(str, '-');
    single_paths(res, pre[i]);
    trav2(*res);
    printf("%d\n", duplicate(*res, pre[i]));
    if (duplicate(*res, pre[i]) == 0)
    {
        printf("no dup\n");
        if (*path == NULL)
        {
            create_path(path, pre[i]);
            create_path(path, pre[i+1]);
            
        }
        else   if (duplicate2(*path, pre[i + 1]) == 0 || duplicate2(*path, pre[i]) == 0)
                create_path(path, pre[i+1]);
      trav(*path);
    }
    if (duplicate(*res, pre[i]) == 1)
    {
        printf("dup\n");
      trav(*path);
        return ;
    }
    free(pre);
} */

t_lst    *search_path(t_lst  *res, char *s, char *e)
{
    char **st;
    char **en;
    char **cut;
    t_lst *tmp;
    t_lst *path;
    char **firstsignal;
    int i = 0;

   path = NULL;
    st = ft_strsplit(s, ' ');
    firstsignal = ft_strsplit(s, ' ');
   // printf("%s\n\n\n", e);
    //return(path);
    en = ft_strsplit(e, ' ');
        if (path == NULL)
            create_path(&path, st[0]);
        tmp = res;
        while (1)
        {
       // tmp = res;
            ft_putstr("THE START!! OF FIRST RUN\n");
        trav(tmp);
            while (tmp)
            {
                if (ft_strcmp(st[0],ft_strreturn(tmp->data, st[0])) == 0  /* || st[0] == firstsignal[0] */)
                {
                    cut = ft_strsplit(tmp->data, '-');
                if (isadded(path, cut[1]) == 1 && isadded(path, cut[0]) == 1)
                {
                    //ft_putstr("heeeeeellllllooooo");
                    //return (path);
                    tmp->data = "";
                    //tmp = tmp->right;
                    cut[0] = NULL;
                    cut[1] = NULL;
                    //break;
                }
                    if (!ft_strcmp(cut[1], ft_strreturn(tmp->data, st[0])) && cut[0] && cut[1]/* && isadded(path, st[0]) == 0 */)
                    {
                         cut = ft_strsplit(tmp->data, '-');
                        create_path(&path, cut[0]);
                        st[0] = cut[0];
                    }
                    else /* if (isadded(path, st[0]) == 0) */if (cut[0] && cut[1])
                    {
                       create_path(&path, cut[1]);
                        st[0] = cut[1];
                    }
                   // printf("\n\n%s\n\n", st[0]);
                    if (ft_strcmp(pos(path, ft_lstlen(path)), en[0]) == 0)
                        return (path);
                }
                tmp = tmp->right;
            }
            //trav(path);
            //return (path);
            ft_putstr("THE END OF FIRST RUN\n");
             if (tmp == NULL)
            {
                tmp = las;
               //trav(tmp);
               //return(path);
                while (tmp)
                {
                    //printf("temp->left = %s\n", tmp->data);
                    //trav(path);
                    trav(tmp);
                    printf("\n\n");
                    if (ft_strcmp(st[0], ft_strsub(tmp->data, 0, ft_strlen(st[0]))) == 0 || (!cut[0] && !cut[1]) )
                    {
                printf("HERE\n");
                        cut = ft_strsplit(tmp->data, '-');
                    if (isadded(path, cut[1]) == 1 && isadded(path, cut[0]) == 1)
                    {
                    tmp->data = "";
                    //tmp = tmp->left;
                    cut[0] = NULL;
                    cut[1] = NULL;
                    //break;
                    //return (path);
                    }
                    printf("my cut === %s\n", cut[1]);
                        if (!ft_strcmp(cut[1], ft_strreturn(tmp->data, st[0])) && cut[0] && cut[1])
                        {
                             cut = ft_strsplit(tmp->data, '-');
                            create_path(&path, cut[0]);
                            st[0] = cut[0];
                        }
                        else if (cut[0] && cut[1])
                        { 
                            create_path(&path, cut[1]);
                            st[0] = cut[1];
                        }
                        if (!ft_strcmp(pos(path, ft_lstlen(path)), en[0]))
                        {

                            return(path);
                        }
                    } 
               //trav(tmp);
                tmp = tmp->left;
                //printf("\n\n num = %d\n\n\n" , isadded(path, st[0]));
            if (!ft_strcmp(pos(path, ft_lstlen(path)), en[0]))
                break;      
                }
            }
            //trav(path);
            //printf("%s\n", en[0]);
            //return(path);
            if (!ft_strcmp(pos(path, ft_lstlen(path)), en[0]))
                break;
                //gcc -Wall -Werror -Wextra check_redu.c display.c ft_lstlen.c ft_strreturn.c links.c position.c valid.c libft/libft.a  
            if (i == 1)
           {
              //printf(">>>>>>>>>>>>>>%s\n",tmp->data);
               //tmp->data = "--";
               //tmp = tmp->left;
               //printf(">>>>>>>>>>>>>>%s\n",tmp->data);
               //tmp = tmp->right;
               //printf(">>>>>>>>>>>>>>%s\n",tmp->data);
               trav(path);
               delete_node(&path, ft_lstlen(path));
               trav(path);
               //return (path);
           } 
           //char **posi;
           //printf("---->>>%s\n", pos(res, ft_lstlen(res)));
           //printf("---->>>%s\n", st[0]);
           
           i++;

            /* posi = ft_strsplit(pos(res, ft_lstlen(res)), '-');
            if (!ft_strcmp(posi[1], en[0]) || !ft_strcmp(posi[0], en[0]))
                break; */
           // break;
        }
        //trav(path);
    return (path);
}//the only problem i have is the end... thats all...
/* ##start
1 23 3
2 16 7
#comment
3 16 3
4 16 5
5 9 3
6 1 5
7 4 8
##end
0 9 5
0-4
0-6
1-3
4-3
5-2
3-5
#another comment
4-2
2-1
7-6
7-2
7-4
6-5 */
/* 1
##start
42_Commandements 2150 3000
Filler 1 1
Filit 12 12
ft_printf 3200 3000
Get_Next_line 3000 3000
libft 2550 3000
Piscine_Reloaded 2350 3000
KFS_4 1850 1700
KFS_3 1950 1800
KFS_2 2050 1700
roger_skyline_2 4100 2250
Piscine_Swift_iOS 2100 3839
Piscine_CPP 2400 4039
Nm_otool 3000 1600
Philosophers 3100 1750
ft_script 2900 1750
RT 3000 3900
42sh 3000 2100
21sh 3000 2300
Matcha 2500 2500
Piscine_OCaml 1872 3410
Corewar 3900 3000
Piscine_PHP 2600 2745
Piscine_Ruby_on_Rails 1850 2750
Docker 1600 2350
Gomoku 4800 3000
N_puzzle 4300 3150
Taskmaster 3200 2200
Expert_System 4300 2850
mod1 3750 3250
Fract'ol 3000 3475
Scop 3000 4100
Hypertube 2370 2370
Camagru 2600 2600
RTv1 3150 3680
lem_in 3600 3000
ft_select 2800 2450
Push_swap 3400 3150
Filer 3400 2850
Wolf3d 2850 3680
minishel 3000 2600
ft_ls 3000 2800
Process_and_Memory 2350 1500
Famine 3000 1200
RainFall 2450 1250
ft_nmap 4100 1750
Red_Tetris 2300 2100
Piscine_Python_Django 1900 2550
H42N42 1690 3280
42run 2900 4250
First_Internship 3000 3001
Savoir_Relier 3550 3550
FdF 3000 3300
roger_skyline_1 3900 2250
Corewar_Championship 3900 3150
Friends_with_Benefits 2100 2300
##end
ft_p 3400 1500
Rubik 4500 3250
Part_time 4110 4110
Root_me_|_Cracking 2550 1150
Snow_Crash 2550 1350
ft_turing 1550 3410
Final_Internship 3000 3002
GBmu 2550 1650
Bomberman 2300 4600
KFS_1 1950 1600
ft_ping 3800 1750
Music_Room 1900 4250
XV 2575 4450
Drivers_and_Interrupts 2200 1500
Open_Project_I 3450 4050
ft_linux 2650 1500
Woody_Woodpacker 3200 1500
libftASM 2800 1500
Root_me_|_App_Systeme 2650 1250
cloud_1 4050 2450
In_the_Shadows 2725 4450
ft_hangouts 2100 4200
Dr_Quine 3000 1400
Abstract_VM 2400 4350
Filesystem 2050 1500
strace 2700 1700
IRC 3400 1700
Darkly 2100 2100
lem_ipc 3850 1450
ComputorV1 4100 3250
little_penguin_1 2500 1500
Swifty_Proteins 1800 4039
Swifty_Companion 2100 4039
Nibbler 2200 4450
KrpSim 4800 3250
Open_Project_II 3518 4250
Piscine_Unity 2650 4250
Particle_System 3000 4400
ft_linear_regression 4600 2800
Malloc 3000 1900
Matt_Daemon 3500 1300
HumanGl 3100 4250
Rushes 2650 3500
C_Exam___Beginner 2350 3450
Zappy 4300 1600
ft_traceroute 3950 1750
ft_ality 1690 3580
42_Commandements-Piscine_Reloaded
Piscine_Reloaded-libft
libft-Filit
Filit-Get_Next_line
# Branche algo
Get_Next_line-ft_printf
ft_printf-Push_swap
ft_printf-Filer
Push_swap-lem_in
Filer-lem_in
lem_in-Corewar
lem_in-mod1
Corewar-First_Internship
Corewar-Corewar_Championship
#  Branche graph
Get_Next_line-FdF
FdF-Fract'ol
Fract'ol-Wolf3d
Fract'ol-RTv1
RTv1-RT
Wolf3d-RT
RT-First_Internship
# Branche sys
Get_Next_line-ft_ls
ft_ls-minishel
minishel-ft_select
minishel-21sh
21sh-Taskmaster
21sh-42sh
42sh-First_Internship
# Branche web
Piscine_PHP-Camagru
Camagru-Matcha
Matcha-Hypertube
Matcha-First_Internship
# Branche web après stage
First_Internship-Friends_with_Benefits
First_Internship-Darkly
First_Internship-Red_Tetris
# Branche algo après stage
First_Internship-ComputorV1
First_Internship-N_puzzle
First_Internship-Expert_System
Expert_System-Gomoku
Expert_System-ft_linear_regression
Expert_System-KrpSim
Expert_System-Rubik
N_puzzle-Rubik
N_puzzle-Gomoku
N_puzzle-ft_linear_regression
N_puzzle-KrpSim
#Branche graph apres stage
First_Internship-Scop
Scop-42run
Scop-HumanGl
Scop-Particle_System
#Branch sys apes stage
First_Internship-Malloc
Malloc-Philosophers
Malloc-ft_script
Malloc-Nm_otool
#Branche sys : cote droit
Nm_otool-ft_p
Nm_otool-IRC
IRC-Zappy
Nm_otool-Zappy
IRC-Matt_Daemon
Nm_otool-Matt_Daemon
IRC-lem_ipc
Nm_otool-lem_ipc
IRC-ft_ping
Nm_otool-ft_ping
ft_ping-ft_traceroute
ft_traceroute-ft_nmap
#Branche sys : côte gauche
Nm_otool-libftASM
libftASM-strace
libftASM-GBmu
libftASM-ft_linux
ft_linux-little_penguin_1
little_penguin_1-Process_and_Memory
Process_and_Memory-Drivers_and_Interrupts
Drivers_and_Interrupts-Filesystem
Filesystem-KFS_1
KFS_1-KFS_2
KFS_2-KFS_3
KFS_3-KFS_4
libftASM-Snow_Crash
Snow_Crash-RainFall
libftASM-Root_me_|_App_Systeme
Root_me_|_App_Systeme-Root_me_|_Cracking
#Branche sys : en haut
Famine-Woody_Woodpacker
Woody_Woodpacker-Nm_otool
Famine-libftASM
First_Internship-Dr_Quine
# les projets "pas reliés"
First_Internship-Piscine_Python_Django
First_Internship-Piscine_Ruby_on_Rails
First_Internship-Docker
First_Internship-Music_Room
# Branche OCaml
First_Internship-Piscine_OCaml
Piscine_OCaml-H42N42
Piscine_OCaml-ft_turing
Piscine_OCaml-ft_ality
# Branche CPP et consors
First_Internship-Piscine_Swift_iOS
First_Internship-Piscine_CPP
Piscine_CPP-Piscine_Unity
Swifty_Companion-Piscine_CPP
Swifty_Companion-Piscine_Swift_iOS
Swifty_Proteins-Swifty_Companion
Piscine_CPP-ft_hangouts
Abstract_VM-Piscine_CPP
Nibbler-Abstract_VM
Bomberman-Abstract_VM
Piscine_Unity-In_the_Shadows
In_the_Shadows-XV
# Open projects
Open_Project_I-First_Internship
Open_Project_II-First_Internship
# cloud
First_Internship-cloud_1
# réseau
First_Internship-roger_skyline_1
roger_skyline_1-roger_skyline_2 */