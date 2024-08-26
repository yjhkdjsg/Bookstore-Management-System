///BOOKSTORE MANAGEMENT PROJECT

#include<stdio.h>
#include<string.h>

//USER-DEFINED FUNCTIONS
void welcomemessage();
void admin();
int login();
void add_book();
void delete_book();
void view_book();
void search_book();
void modify_book();
int unique_book_id();
int unique_book_name();
void display_desired_book(int);
void add_to_card();
void view_cart();
int unique_username();

//GLOBAL VARIABLE FOR NUMBER OF DISTINCT BOOKS IN THE BOOKSTORE
int count=0;

//GLOBAL VARIABLE FOR NUMBER OF USERS IN THE BOOKSTORE
int countuser=0;

//GLOBAL VARIABLE FOR NUMBER OF BOOKS IN CART
int cartbooks=0;

//BASIC STRUCTURE OF THE BOOKSTORE DATABASE
struct books
{
    int book_id;
    char book_name[50];
    char book_author[30];
    char book_publications[30];
    int book_pages;
    int book_price;
    int book_quantity;
}bookstore[100];

struct user
{
char user_name[20];
char pass_word[8];
}users[100];

struct Cart
{
    int books_id;
    char books_name[50];
    char books_author[30];
    char books_publications[30];
    int books_pages;
    int books_price;
    int books_quantity;
}cart[100];

int main()
{
    welcomemessage();
    admin();
    int choice1, main_choice,choice2,log;
    choice1=1;
    while(choice1==1)
    {
        switch(login())
        {
            case 1:
                printf("\tSUCCESSFULLY SIGNED IN!");
                main_choice=1;
                while(main_choice!=0)
                {
                    printf("\n\n\t********BOOK STORE MAIN MENU********\n");
                    printf("\t0. EXIT\n");
                    printf("\t1. ADD BOOKS\n");
                    printf("\t2. DELETE BOOKS\n");
                    printf("\t3. VIEW ALL BOOKS\n");
                    printf("\t4. SEARCH BOOKS\n");
                    printf("\t5. MODIFY BOOKS\n");
                    printf("\n\tENTER YOUR CHOICE(0,1,2,3,4,5): ");
                    scanf("%d",&main_choice);

                    switch(main_choice)
                    {
                        //for exiting the menu
                        case 0:
                        {
                            printf("\n\tEXITING THE PROGRAM!\n");
                            break;
                        }

                        //for adding books
                        case 1:
                        {
                            add_book();
                            break;
                        }

                        //for deleting books
                        case 2:
                        {
                            delete_book();
                            break;
                        }

                        //for viewing all books
                        case 3:
                        {
                            view_book();
                            break;
                        }

                        //for searching books
                        case 4:
                        {
                            search_book();
                            break;
                        }

                        //for modifying details of books
                        case 5:
                        {
                            modify_book();
                            break;
                        }

                        //if the input is invalid
                        default:
                        {
                            printf("\n\tINVALID INPUT!");
                        }
                    }
                }
            break;

            case 2:
                printf("\tSUCCESSFULLY SIGNED IN!");
                main_choice=1;
                while(main_choice!=0)
                {
                    printf("\n\n\t********BOOK STORE MAIN MENU********\n");
                    printf("\t0. EXIT\n");
                    printf("\t1. VIEW ALL BOOKS\n");
                    printf("\t2. SEARCH BOOKS\n");
                    printf("\t3. ADD BOOKS TO CART\n");
                    printf("\t4. VIEW CART\n");
                    printf("\n\tENTER YOUR CHOICE(0,1,2,3,4): ");
                    scanf("%d",&main_choice);

                    switch(main_choice)
                    {

                        //for exiting the menu
                        case 0:
                        {
                            printf("\n\tEXITING THE PROGRAM!\n");
                            break;
                        }

                        //for viewing books
                        case 1:
                        {
                            view_book();
                            break;
                        }

                        //for searching a book
                        case 2:
                        {
                            search_book();
                            break;
                        }

                        //for adding a book to cart
                        case 3:
                        {
                            add_to_cart();
                            break;
                        }

                        //for viewing cart
                        case 4:
                        {
                            view_cart();
                            break;
                        }

                        //if the input is invalid
                        default:
                        {
                            printf("\n\tINVALID INPUT!");
                        }
                    }
                }
                break;

            case 0:
                printf("\tINCORRECT USERNAME OR PASSWORD!");
                break;

            default:
                printf("\tCOULDN'T SIGN IN!");
        }

    //CHOICE TO LOG IN AGAIN
    printf("\n\tDO YOU WISH TO LOGIN AGAIN? \n\t1. Yes\n\t2. No\n");
    printf("\tENTER YOUR CHOICE: ");
    scanf("%d",&choice2);
    choice1=choice2;
    }
    return 0;
}

//USER-DEFINED FUNCTION FOR WELCOME MESSAGE
void welcomemessage()
{
    FILE *file;
    char line[100];
    file=fopen("welcome.txt","w+");
    if(file==NULL)
    {
        printf("FILE COULD NOT BE OPENED!");
        exit(1);
    }
    fputs("    **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**   \n",file);
    fputs("        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=       \n",file);
    fputs("        =                 WELCOME                   =       \n",file);
    fputs("        =                   TO                      =       \n",file);
    fputs("        =                BOOKSTORE                  =       \n",file);
    fputs("        =             MANAGEMENT SYSTEM             =       \n",file);
    fputs("        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=       \n",file);
    fputs("    **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**",file);
    fseek(file,0,SEEK_SET);
    while (fgets(line,1000,file)!= NULL)
    {
        printf("%s",line);
    }
    fclose(file);
}

//USER-DEFINED FUNCTION TO CREATE FILE FOR ADMIN ID AND PASSWORD
void admin()
{
    FILE *file;
    file=fopen("admin.txt","w");
    if(file==NULL)
    {
        printf("FILE COULD NOT BE OPENED!");
        exit(1);
    }
    fputs("ADMIN\n",file);
    fputs("12345678",file);
    fclose(file);
}

//USER-DEFINED FUNCTION TO LOGIN
int login()
{
    FILE *file;
    int ch;
    char adminname[20],adminpass[8];
    char username[20],password[8];
    file=fopen("admin.txt","r");
    if(file==NULL)
    {
        printf("\nFILE COULD NOT BE OPENED!");
        exit(1);
    }
    fgets(adminname,20,file);
    fgets(adminpass,20,file);

    printf("\n\t1. ADMIN\n\t2. USER\n");
    printf("\tENTER YOUR CHOICE: ");
    scanf("%d",&ch);

    if(ch==1)
    {
        fflush(stdin);
        printf("\n\tLOGIN AS ADMIN\n");
        printf("\tENTER USERNAME: ");
        gets(username);
        printf("\tENTER PASSWORD: ");
        gets(password);
        if((strcmp(adminname,username)==0)&&(strcmp(adminpass,password)==0))
        {
            countuser++;
            return 1;
        }
    }

    else if(ch==2)
    {
        printf("\t1. SIGN UP\n");
        printf("\t2. LOGIN\n");
        int choice;

        printf("\tENTER YOUR CHOICE: ");
        scanf("%d",&choice);

        if(choice==1)
        {
            printf("\tENTER USERNAME: ");
            scanf("\n%s",users[countuser].user_name);
            if(unique_username()==0)
            {
                printf("\tUSERNAME EXISTS!\nENTER A UNIQUE USERNAME!\n");
            }
            printf("\tENTER PASSWORD: ");
            scanf("\n%s",users[countuser].pass_word);
            countuser++;
            return 2;
        }

        else if(choice==2)
        {
            printf("\tENTER USERNAME: ");
            scanf("\n%s",username);
            printf("\tENTER PASSWORD: ");
            scanf("\n%s",password);

            for(int i=0;i<countuser;i++)
            {

                if(strcmp(username,users[i].user_name)&&(password,users[i].pass_word)==0)
                {
                    return 2;
                }
            }
        }

        else
        {
            printf("\n\tINCORRECT INPUT!\n");
        }
    }
    else
    {
        printf("\n\tINCORRECT INPUT!\n");
    }
    fclose(file);
}

//USER-DEFINED FUNCTION TO CHECK UNIQUE USERNAME
int unique_username()
{
    int i=0, flag=1;
    for(i=0; i<countuser; i++)
    {
        if(strcmp(users[countuser].user_name,users[i].user_name)==0)
        {
            flag=0;
            break;
        }
    }
    if(flag==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//USER-DEFINED FUNCTION TO ADD BOOK INTO THE BOOKSTORE
void add_book()
{
    FILE *file;
    file=fopen("bookdata.txt","a");
    if(file==NULL)
    {
        printf("FILE COULD NOT BE OPENED!");
        exit(1);
    }
    printf("\n\tENTER BOOK ID: ");
    scanf("%d", &bookstore[count].book_id);
    if(unique_book_id()==0)
    {
        printf("\tPLEASE ENTER A UNIQUE BOOK ID!\n");
        printf("\tRETURNING BACK TO THE MAIN MENU!\n");
        return;
    }
    printf("\tENTER BOOK NAME: ");
    fflush(stdin);
    gets(bookstore[count].book_name);

    if(unique_book_name()==0)
    {
        printf("\tPLEASE ENTER A UNIQUE BOOK NAME!\n");
        printf("\tRETURNING BACK TO THE MAIN MENU!\n");
        return;
    }
    printf("\tENTER BOOK AUTHOR: ");
    gets(bookstore[count].book_author);

    printf("\tENTER PUBLICATIONS: ");
    gets(bookstore[count].book_publications);

    printf("\tENTER BOOK PAGES: ");
    scanf("%d", &bookstore[count].book_pages);

    printf("\tENTER BOOK PRICE: ");
    scanf("%d", &bookstore[count].book_price);

    printf("\tENTER BOOK QUANTITY: ");
    scanf("%d", &bookstore[count].book_quantity);

    char name[50];
    strcpy(name,bookstore[count].book_name);
    fprintf(file,"%s\n",name);
    count++;
    fclose(file);
}

//USER-DEFINED FUNCTION TO DELETE BOOK FROM THE BOOKSTORE
void delete_book()
{
    int choice=0;
    printf("\n\t*********DELETE SUB MENU:**********\n");
    printf("\t0. BACK TO MAIN MENU\n");
    printf("\t1. DELETE BY : BOOK ID\n");
    printf("\t2. DELETE BY : BOOK NAME\n");
    printf("\t3. DELETE ALL RECORDS!\n");

    printf("\n\tENTER YOUR CHOICE(0,1,2,3): ");
    scanf("%d", &choice);

    view_book();

    //EXITING TO MAIN MENU WITHOUT DELETING ANY BOOK
    if(choice==0)
    {
        printf("\tRETURN BACK TO THE MAIN MENU!\n");
    }

    //DELETING BY BOOK_ID
    else if(choice==1)
    {
        int book_id_to_delete=0;
        printf("\tENTER BOOK ID TO DELETE: ");
        scanf("%d", &book_id_to_delete);

        int i=0, flag=0;
        for(i=0; i<count; i++)
        {
            if(book_id_to_delete == bookstore[i].book_id)
            {
                int j=0;
                for(j=i; j<count; j++)
                {
                    bookstore[j]=bookstore[j+1];
                }
                count--;
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            printf("\tBOOK WITH BOOK ID %d HAS BEEN DELETED!\n", book_id_to_delete);
        }
        else
        {
            printf("\tBOOK WITH BOOK ID %d NOT FOUND!\n", book_id_to_delete);
        }
        view_book();
    }

    //DELETING BY BOOK_NAME
    else if(choice==2)
    {
        char book_name_to_delete[50];
        fflush(stdin);
        printf("\tENTER BOOK NAME TO DELETE: ");
        gets(book_name_to_delete);

        int i=0, flag=0;
        for(i=0; i<count; i++)
        {
            if(strcmp(book_name_to_delete, bookstore[i].book_name)==0)
            {
                int j=0;
                for(j=i; j<count; j++)
                {
                    bookstore[j]=bookstore[j+1];
                }
                count--;
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            printf("\tBOOK WITH BOOK_NAME %s HAS BEEN DELETED!\n", book_name_to_delete);
        }
        else
        {
            printf("\tBOOK WITH BOOK_NAME %s NOT FOUND!\n", book_name_to_delete);
        }
        view_book();
    }

    //DELETING ALL RECORDS
    else if(choice==3)
    {
        count=0;
        printf("\tALL RECORDS HAVE BEEN DELETED!\n");
        view_book();
    }

    //DEFAULT CONDITION FOR INVALID INPUT
    else
    {
        printf("\tINVALID INPUT!\n");
        printf("\tRETURNING BACK TO THE MAIN MENU!\n");
    }
    return;
}

//USER-DEFINED FUNCTION TO VIEW ALL BOOKS OF THE BOOKSTORE
void view_book()
{
	if(count==0)
	{
    	printf("\tBOOKSTORE IS EMPTY!\n");
    	return;
	}
	else
	{
    	int i=0;

    	//PRINTING TABLE FOR ALL THE BOOKS IN THE bookstore
    	for(i=0; i<count; i++)
    	{
        	//Printing S.No.
        	printf("\tS.No. : %d\n", i+1);

        	//Printing Book_ID
        	printf("\tBOOK ID : %d\n", bookstore[i].book_id);

        	//Printing Book_Name
        	printf("\tBOOK NAME : %s\n", bookstore[i].book_name);

        	//Printing Book_Author
        	printf("\tBOOK AUTHOR : %s\n", bookstore[i].book_author);

        	//Printing Book_Publications
        	printf("\tBOOK PUBLICATIONS : %s\n", bookstore[i].book_publications);

        	//Printing Book_Pages
        	printf("\tBOOK PAGES : %d\n", bookstore[i].book_pages);

        	//Printing Book_Price
        	printf("\tBOOK PRICE : %d\n", bookstore[i].book_price);

        	//Printing Book_Quantity
        	printf("\tBOOK QUANTITY : %d\n", bookstore[i].book_quantity);
    	}
	}
}

//USER-DEFINED FUNCTION TO SEARCH A BOOK IN THE BOOKSTORE
void search_book()
{
    int choice=0;
    printf("\n\t*********SEARCH SUB MENU:**********\n");

    printf("\t0. BACK TO MAIN MENU\n");
    printf("\t1. SEARCH BY : BOOK ID\n");
    printf("\t2. SEARCH BY : BOOK NAME\n");
    printf("\t3. SEARCH BY : BOOK AUTHOR\n");
    printf("\t4. SEARCH BY : BOOK PUBLICATIONS\n");
    printf("\t5. SEARCH BY : BOOK PAGES\n");
    printf("\t6. SEARCH BY : BOOK PRICE\n");
    printf("\t7. SEARCH BY : BOOK QUANTITY\n");

    printf("\n\tENTER YOUR CHOICE(0,1,2,3,4,5,6,7): ");
    scanf("%d", &choice);

    //EXITING TO MAIN MENU WITHOUT SEARCHING ANY BOOK
    if(choice==0)
    {
        printf("\tRETURNING BACK TO THE MAIN MENU!\n");
    }

    //SEARCHING BY BOOK_ID
    else if(choice==1)
    {
        int book_id_to_search=0;
        printf("\tENTER BOOK ID TO SEARCH: ");
        scanf("%d", &book_id_to_search);

        int i=0, flag=0;
        for(i=0; i<count; i++)
        {
            if(book_id_to_search == bookstore[i].book_id)
            {
                flag=1;
                //Printing S.No.
                printf("\tS.No. : %d\n", i+1);

                //Printing Book_ID
                printf("\tBOOK ID : %d\n", bookstore[i].book_id);

                //Printing Book_Name
                printf("\tBOOK NAME : %s\n", bookstore[i].book_name);

                //Printing Book_Author
                printf("\tBOOK AUTHOR : %s\n", bookstore[i].book_author);

                //Printing Book_Publications
                printf("\tBOOK PUBLICATIONS : %s\n", bookstore[i].book_publications);

                //Printing Book_Pages
                printf("\tBOOK PAGES : %d\n", bookstore[i].book_pages);

                //Printing Book_Price
                printf("\tBOOK PRICE : %d\n", bookstore[i].book_price);

                //Printing Book_Quantity
                printf("\tBOOK QUANTITY : %d\n", bookstore[i].book_quantity);
                break;
            }
        }
        if(flag==0)
        {
            printf("\tBook_ID not found.\n");
            printf("\tReturning Back to the Main Menu.\n");
        }
    }

    //SEARCHING BY BOOK_NAME
    else if(choice==2)
    {
        char book_name_to_search[50];
        printf("\tENTER BOOK NAME TO SEARCH: ");
        fflush(stdin);
        gets(book_name_to_search);

        int i=0, flag=0;
        for(i=0; i<count; i++)
        {
            if(strcmp(book_name_to_search, bookstore[i].book_name)==0)
            {
                flag=1;
                //Printing S.No.
                printf("\tS.No. : %d\n", i+1);

                //Printing Book_ID
                printf("\tBOOK ID : %d\n", bookstore[i].book_id);

                //Printing Book_Name
                printf("\tBOOK NAME : %s\n", bookstore[i].book_name);

                //Printing Book_Author
                printf("\tBOOK AUTHOR : %s\n", bookstore[i].book_author);

                //Printing Book_Publications
                printf("\tBOOK PUBLICATIONS : %s\n", bookstore[i].book_publications);

                //Printing Book_Pages
                printf("\tBOOK PAGES : %d\n", bookstore[i].book_pages);

                //Printing Book_Price
                printf("\tBOOK PRICE : %d\n", bookstore[i].book_price);

                //Printing Book_Quantity
                printf("\tBOOK QUANTITY : %d\n", bookstore[i].book_quantity);
                break;
            }
        }
        if(flag==0)
        {
            printf("\tBOOK NAME NOT FOUND!\n");
            printf("\tRETURNING BACK TO THE MAIN MENU!\n");
        }
    }

    //SEARCHING BY BOOK_AUTHOR
    else if(choice==3)
    {
        char book_author_to_search[30];
        printf("\tENTER BOOK AUTHOR TO SEARCH: ");
        fflush(stdin);
        gets(book_author_to_search);

        int i=0, flag=0;
        for(i=0; i<count; i++)
        {
            if(strcmp(book_author_to_search, bookstore[i].book_author)==0)
            {
                flag=1;
                //Printing S.No.
                printf("\tS.No. : %d\n", i+1);

                //Printing Book_ID
                printf("\tBOOK ID : %d\n", bookstore[i].book_id);

                //Printing Book_Name
                printf("\tBOOK NAME : %s\n", bookstore[i].book_name);

                //Printing Book_Author
                printf("\tBOOK AUTHOR : %s\n", bookstore[i].book_author);

                //Printing Book_Publications
                printf("\tBOOK PUBLICATIONS : %s\n", bookstore[i].book_publications);

                //Printing Book_Pages
                printf("\tBOOK PAGES : %d\n", bookstore[i].book_pages);

                //Printing Book_Price
                printf("\tBOOK PRICE : %d\n", bookstore[i].book_price);

                //Printing Book_Quantity
                printf("\tBOOK QUANTITY : %d\n", bookstore[i].book_quantity);
            }
        }
        if(flag==0)
        {
            printf("\tBOOK NOT FOUND WITH THE GIVEN %s BOOK_AUTHOR\n", book_author_to_search);
            printf("\tReturning Back to the Main Menu.\n");
        }
    }

    //SEARCHING BY BOOK_PUBLICATIONS
    else if(choice==4)
    {
        char book_publications_to_search[30];
        printf("\tENTER BOOK PUBLICATIONS TO SEARCH: ");
        fflush(stdin);
        gets(book_publications_to_search);

        int i=0, flag=0;
        for(i=0; i<count; i++)
        {
            if(strcmp(book_publications_to_search, bookstore[i].book_publications)==0)
            {
                flag=1;
                //Printing S.No.
                printf("\tS.No. : %d\n", i+1);

                //Printing Book_ID
                printf("\tBOOK ID : %d\n", bookstore[i].book_id);

                //Printing Book_Name
                printf("\tBOOK NAME : %s\n", bookstore[i].book_name);

                //Printing Book_Author
                printf("\tBOOK AUTHOR : %s\n", bookstore[i].book_author);

                //Printing Book_Publications
                printf("\tBOOK PUBLICATIONS : %s\n", bookstore[i].book_publications);

                //Printing Book_Pages
                printf("\tBOOK PAGES : %d\n", bookstore[i].book_pages);

                //Printing Book_Price
                printf("\tBOOK PRICE : %d\n", bookstore[i].book_price);

                //Printing Book_Quantity
                printf("\tBOOK QUANTITY : %d\n", bookstore[i].book_quantity);
            }
        }
        if(flag==0)
        {
            printf("\tBOOK NOT FOUND WITH THE GIVEN %s BOOK_PUBLICATION\n", book_publications_to_search);
            printf("\tReturning Back to the Main Menu.\n");
        }
    }

    //SEARCHING BY BOOK_PAGES
    else if(choice==5)
    {
        int book_pages_to_search=0;
        printf("\tENTER BOOK PAGES TO SEARCH: ");
        scanf("%d", &book_pages_to_search);

        int i=0, flag=0;
        for(i=0; i<count; i++)
        {
            if(book_pages_to_search==bookstore[i].book_pages)
            {
                flag=1;
                //Printing S.No.
                printf("\tS.No. : %d\n", i+1);

                //Printing Book_ID
                printf("\tBOOK ID : %d\n", bookstore[i].book_id);

                //Printing Book_Name
                printf("\tBOOK NAME : %s\n", bookstore[i].book_name);

                //Printing Book_Author
                printf("\tBOOK AUTHOR : %s\n", bookstore[i].book_author);

                //Printing Book_Publications
                printf("\tBOOK PUBLICATIONS : %s\n", bookstore[i].book_publications);

                //Printing Book_Pages
                printf("\tBOOK PAGES : %d\n", bookstore[i].book_pages);

                //Printing Book_Price
                printf("\tBOOK PRICE : %d\n", bookstore[i].book_price);

                //Printing Book_Quantity
                printf("\tBOOK QUANTITY : %d\n", bookstore[i].book_quantity);
            }
        }
        if(flag==0)
        {
            printf("\tBOOK NOT FOUND WITH THE GIVEN %d BOOK PAGES\n", book_pages_to_search);
            printf("\tRETURNING BACK TO THE MAIN MENU!\n");
        }
    }

    //SEARCHING BY BOOK_PRICE
    else if(choice==6)
    {
        int book_price_to_search=0;
        printf("\tENTER BOOK PRICE TO SEARCH: ");
        scanf("%d", &book_price_to_search);

        int i=0, flag=0;
        for(i=0; i<count; i++)
        {
            if(book_price_to_search==bookstore[i].book_price)
            {
                flag=1;
                //Printing S.No.
                printf("\tS.No. : %d\n", i+1);

                //Printing Book_ID
                printf("\tBOOK ID : %d\n", bookstore[i].book_id);

                //Printing Book_Name
                printf("\tBOOK NAME : %s\n", bookstore[i].book_name);

                //Printing Book_Author
                printf("\tBOOK AUTHOR : %s\n", bookstore[i].book_author);

                //Printing Book_Publications
                printf("\tBOOK PUBLICATIONS : %s\n", bookstore[i].book_publications);

                //Printing Book_Pages
                printf("\tBOOK PAGES : %d\n", bookstore[i].book_pages);

                //Printing Book_Price
                printf("\tBOOK PRICE : %d\n", bookstore[i].book_price);

                //Printing Book_Quantity
                printf("\tBOOK QUANTITY : %d\n", bookstore[i].book_quantity);
            }
        }
        if(flag==0)
        {
            printf("\tBOOK NOT FOUND WITH THE GIVEN %d BOOK PRICE\n", book_price_to_search);
            printf("\tRETURNING BACK TO THE MAIN MENU!\n");
        }
    }

    //SEARCHING BY BOOK_QUANTITY
    else if(choice==7)
    {
        int book_quantity_to_search=0;
        printf("\tENTER BOOK QUANTITY TO SEARCH: ");
        scanf("%d", &book_quantity_to_search);

        int i=0, flag=0;
        for(i=0; i<count; i++)
        {
            if(book_quantity_to_search==bookstore[i].book_quantity)
            {
                flag=1;
                //Printing S.No.
                printf("\tS.No. : %d\n", i+1);

                //Printing Book_ID
                printf("\tBOOK ID : %d\n", bookstore[i].book_id);

                //Printing Book_Name
                printf("\tBOOK NAME : %s\n", bookstore[i].book_name);

                //Printing Book_Author
                printf("\tBOOK AUTHOR : %s\n", bookstore[i].book_author);

                //Printing Book_Publications
                printf("\tBOOK PUBLICATIONS : %s\n", bookstore[i].book_publications);

                //Printing Book_Pages
                printf("\tBOOK PAGES : %d\n", bookstore[i].book_pages);

                //Printing Book_Price
                printf("\tBOOK PRICE : %d\n", bookstore[i].book_price);

                //Printing Book_Quantity
                printf("\tBOOK QUANTITY : %d\n", bookstore[i].book_quantity);
                break;
            }
        }
        if(flag==0)
        {
            printf("\tBOOK NOT FOUND WITH THE GIVEN %d BOOK QUANTITY\n", book_quantity_to_search);
            printf("\tRETURNING BACK TO THE MAIN MENU!\n");
        }
    }
    else
    {
        printf("\tINVALID INPUT!\n");
        printf("\tRETURNING BACK TO THE MAIN MENU!\n");
    }
    return;
}

//USER-DEFINED FUNCTION TO MODIFY BOOK DATA IN THE BOOKSTORE
void modify_book()
{
    int choice=0;
    printf("\n\t********MODIFY MENU*********\n");
    printf("\t0. BACK TO MAIN MENU!\n");
    printf("\t1. SEARCH FOR BOOK USING BOOK ID\n");
    printf("\t2. SEARCH FOR BOOK USING BOOK NAME\n");
    printf("\n\tENTER YOUR CHOICE(0,1,2): ");
    scanf("%d", &choice);

    //RETURNING TO THE MAIN MENU
    if(choice==0)
    {
        printf("\tRETURNING BACK TO MAIN MENU!\n");
        return;
    }

    //MODIFYING USING BOOK_ID
    else if(choice==1)
    {
        int book_id_to_search;
        view_book();
        printf("\tENTER BOOK ID TO SEARCH FOR MODIFYING BOOK: ");
        scanf("%d", &book_id_to_search);

        int i=0, index=0;
        for(i=0; i<count; i++)
        {
            if(book_id_to_search==bookstore[i].book_id)
            {
                index=i;
                break;
            }
            else
            {
                index=-1;
            }
        }
        if(index==-1)
        {
            printf("\tBOOK ID %d NOT FOUND.\n", book_id_to_search);
        }
        else
        {
            int choice_1=0;
            printf("\tBOOK ID %d FOUND.\n", book_id_to_search);
            display_desired_book(index);

            printf("\n\t********MODIFY SUB-MENU********\n");
            printf("\t0. BACK TO MAIN MENU\n");
            printf("\t1. MODIFY BOOK ID\n");
            printf("\t2. MODIFY BOOK NAME\n");
            printf("\t3. MODIFY BOOK AUTHOR\n");
            printf("\t4. MODIFY BOOK PUBLICATIONS\n");
            printf("\t5. MODIFY BOOK PAGES\n");
            printf("\t6. MODIFY BOOK PRICE\n");
            printf("\t7. MODIFY BOOK QUANTITY\n");
            printf("\n\tENTER YOUR CHOICE(0,1,2,3,4,5,6,7): ");
            scanf("%d", &choice_1);

            //RETURNING TO MAIN MENU
            if(choice_1==0)
            {
                printf("\n\tRETURNING BACK TO THE MAIN MENU!\n");
            }

            //MODIFYING BOOK_ID
            else if(choice_1==1)
            {
                int new_book_id;
                printf("\tMODIFYING BOOK ID\n");
                printf("\tENTER NEW BOOK ID: ");
                scanf("%d", &new_book_id);
                printf("\tOLD BOOK ID : %d ", bookstore[index].book_id);
                bookstore[index].book_id=new_book_id;
                printf("HAS BEEN CHANGED TO : %d\n", bookstore[index].book_id);
            }

            //MODIFYING BOOK_NAME
            else if(choice_1==2)
            {
                char new_book_name[50];
                printf("\tMODIFYING BOOK NAME\n");
                printf("\tENTER NEW BOOK NAME: ");
                fflush(stdin);
                gets(new_book_name);
                printf("\tOLD BOOK NAME : %s ", bookstore[index].book_name);
                strcpy(bookstore[index].book_name, new_book_name);
                printf("HAS BEEN CHANGED TO: %s\n", bookstore[index].book_name);
            }

            //MODIFYING BOOK_AUTHOR
            else if(choice_1==3)
            {
                char new_book_author[30];
                printf("\tMODIFYING BOOK AUTHOR\n");
                printf("\tENTER NEW BOOK AUTHOR: ");
                fflush(stdin);
                gets(new_book_author);
                printf("\tOLD BOOK AUTHOR : %s ", bookstore[index].book_author);
                strcpy(bookstore[index].book_author, new_book_author);
                printf("HAS BEEN CHANGED TO : %s\n", bookstore[index].book_author);
            }

            //MODIFYING BOOK_PUBLICATIONS
            else if(choice_1==4)
            {
                char new_book_publications[30];
                printf("\tMODIFYING BOOK PUBLICATIONS\n");
                printf("\tENTER NEW BOOK PUBLICATIONS : ");
                fflush(stdin);
                gets(new_book_publications);
                printf("\tOLD BOOK PUBLICATIONS : %s ", bookstore[index].book_publications);
                strcpy(bookstore[index].book_publications, new_book_publications);
                printf("HAVE BEEN CHANGED TO : %s\n", bookstore[index].book_publications);
            }

            //MODIFYING BOOK_PAGES
            else if(choice_1==5)
            {
                int new_book_pages;
                printf("\tMODIFYING BOOK PAGES\n");
                printf("\tENTER NEW BOOK PAGES : ");
                scanf("%d", &new_book_pages);
                printf("\tOLD BOOK PAGES: %d ", bookstore[index].book_pages);
                bookstore[index].book_pages=new_book_pages;
                printf("HAVE BEEN CHANGED TO : %d\n", bookstore[index].book_pages);
            }

            //MODIFYING BOOK_PRICE
            else if(choice_1==6)
            {
                int new_book_price;
                printf("\tMODIFYING BOOK PRICE\n");
                printf("\tENTER NEW BOOK PRICE : ");
                scanf("%d", &new_book_price);
                printf("\tOLD BOOK PRICE : %d ", bookstore[index].book_price);
                bookstore[index].book_price=new_book_price;
                printf("HAS BEEN CHANGED TO : %d\n", bookstore[index].book_price);
            }

            //MODIFYING BOOK_QUANTITY
            else if(choice_1==7)
            {
                int new_book_quantity;
                printf("\tMODIFYING BOOK QUANTITY\n");
                printf("\tENTER NEW BOOK QUANTITY : ");
                scanf("%d", &new_book_quantity);
                printf("\tOLD BOOK QUANTITY: %d ", bookstore[index].book_quantity);
                bookstore[index].book_quantity=new_book_quantity;
                printf("HAS BEEN CHANGED TO : %d\n", bookstore[index].book_quantity);
            }

            //DEFAULT FOR WRONG INPUT
            else
            {
                printf("\tINVALID INPUT!");
            }
        }
    }

    //MODIFYING USING BOOK_Name
    else if(choice==2)
    {
        char book_name_to_search[50];
        printf("\t\tEnter Book_Name to search for the book to Modify: ");
        fflush(stdin);
        gets(book_name_to_search);

        int i=0, index=0;
        for(i=0; i<count; i++)
        {
            if(strcmp(book_name_to_search, bookstore[i].book_name)==0)
            {
                index=i;
                break;
            }
            else
            {
                index=-1;
            }
        }
        if(index==-1)
        {
            printf("\tBOOK NAME %s NOT FOUND.\n", book_name_to_search);
        }
        else
        {
            int choice_1=0;
            printf("\tBook_Name %s FOUND.\n", book_name_to_search);
            display_desired_book(index);

            printf("\n\t********MODIFY SUB-MENU********\n");
            printf("\t0. BACK TO MAIN MENU\n");
            printf("\t1. MODIFY BOOK ID\n");
            printf("\t2. MODIFY BOOK NAME\n");
            printf("\t3. MODIFY BOOK AUTHOR\n");
            printf("\t4. MODIFY BOOK PUBLICATIONS\n");
            printf("\t5. MODIFY BOOK PAGES\n");
            printf("\t6. MODIFY BOOK PRICE\n");
            printf("\t7. MODIFY BOOK QUANTITY\n");
            printf("\n\tENTER YOUR CHOICE(0,1,2,3,4,5,6,7): ");
            scanf("%d", &choice_1);

            //RETURNING TO MAIN MENU
            if(choice_1==0)
            {
                printf("\n\tRETURNING BACK TO THE MAIN MENU!\n");
            }

            //MODIFYING BOOK_ID
            else if(choice_1==1)
            {
                int new_book_id;
                printf("\tMODIFYING BOOK ID\n");
                printf("\tENTER NEW BOOK ID: ");
                scanf("%d", &new_book_id);
                printf("\tOLD BOOK ID : %d ", bookstore[index].book_id);
                bookstore[index].book_id=new_book_id;
                printf("HAS BEEN CHANGED TO : %d\n", bookstore[index].book_id);
            }

            //MODIFYING BOOK_NAME
            else if(choice_1==2)
            {
                char new_book_name[50];
                printf("\tMODIFYING BOOK NAME\n");
                printf("\tENTER NEW BOOK NAME: ");
                fflush(stdin);
                gets(new_book_name);
                printf("\tOLD BOOK NAME : %s ", bookstore[index].book_name);
                strcpy(bookstore[index].book_name, new_book_name);
                printf("HAS BEEN CHANGED TO: %s\n", bookstore[index].book_name);
            }

            //MODIFYING BOOK_AUTHOR
            else if(choice_1==3)
            {
                char new_book_author[30];
                printf("\tMODIFYING BOOK AUTHOR\n");
                printf("\tENTER NEW BOOK AUTHOR: ");
                fflush(stdin);
                gets(new_book_author);
                printf("\tOLD BOOK AUTHOR : %s ", bookstore[index].book_author);
                strcpy(bookstore[index].book_author, new_book_author);
                printf("HAS BEEN CHANGED TO : %s\n", bookstore[index].book_author);
            }

            //MODIFYING BOOK_PUBLICATIONS
            else if(choice_1==4)
            {
                char new_book_publications[30];
                printf("\tMODIFYING BOOK PUBLICATIONS\n");
                printf("\tENTER NEW BOOK PUBLICATIONS : ");
                fflush(stdin);
                gets(new_book_publications);
                printf("\tOLD BOOK PUBLICATIONS : %s ", bookstore[index].book_publications);
                strcpy(bookstore[index].book_publications, new_book_publications);
                printf("HAVE BEEN CHANGED TO : %s\n", bookstore[index].book_publications);
            }

            //MODIFYING BOOK_PAGES
            else if(choice_1==5)
            {
                int new_book_pages;
                printf("\tMODIFYING BOOK PAGES\n");
                printf("\tENTER NEW BOOK PAGES : ");
                scanf("%d", &new_book_pages);
                printf("\tOLD BOOK PAGES: %d ", bookstore[index].book_pages);
                bookstore[index].book_pages=new_book_pages;
                printf("HAVE BEEN CHANGED TO : %d\n", bookstore[index].book_pages);
            }

            //MODIFYING BOOK_PRICE
            else if(choice_1==6)
            {
                int new_book_price;
                printf("\tMODIFYING BOOK PRICE\n");
                printf("\tENTER NEW BOOK PRICE : ");
                scanf("%d", &new_book_price);
                printf("\tOLD BOOK PRICE : %d ", bookstore[index].book_price);
                bookstore[index].book_price=new_book_price;
                printf("HAS BEEN CHANGED TO : %d\n", bookstore[index].book_price);
            }

            //MODIFYING BOOK_QUANTITY
            else if(choice_1==7)
            {
                int new_book_quantity;
                printf("\tMODIFYING BOOK QUANTITY\n");
                printf("\tENTER NEW BOOK QUANTITY : ");
                scanf("%d", &new_book_quantity);
                printf("\tOLD BOOK QUANTITY: %d ", bookstore[index].book_quantity);
                bookstore[index].book_quantity=new_book_quantity;
                printf("HAS BEEN CHANGED TO : %d\n", bookstore[index].book_quantity);
            }

            //DEFAULT FOR WRONG INPUT
            else
            {
                printf("\tINVALID INPUT!");
            }
        }
        printf("\tRETURNING BACK TO THE MAIN MENU!\n");
        return;
    }
}

//USER-DEFINED FUNCTION TO CHECK UNIQUE BOOK ID
int unique_book_id()
{
    int i=0, flag=1;
    for(i=0; i<count; i++)
    {
        if(bookstore[count].book_id==bookstore[i].book_id)
        {
            flag=0;
            break;
        }
    }
    if(flag==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int unique_book_name()
{
    int i=0, flag=1;
    for(i=0; i<count; i++)
    {
        if(strcmp(bookstore[count].book_name,bookstore[i].book_name)==0)
        {
            flag=0;
            break;
        }
    }
    if(flag==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//USER-DEFINED FUNCTION TO DISPLAY DESIRED BOOK
void display_desired_book(int index)
{
    int i=0;
    for(i=0; i<count; i++)
    {
        if(i==index)
        {
            //PRINTING TABLE FOR THE DESIRED BOOK IN THE bookstore
            //Printing S.No.
            printf("\tS.No. : %d\n", i+1);

            //Printing Book_ID
            printf("\tBOOK ID : %d\n", bookstore[i].book_id);

            //Printing Book_Name
            printf("\tBOOK NAME : %s\n", bookstore[i].book_name);

            //Printing Book_Author
            printf("\tBOOK AUTHOR : %s\n", bookstore[i].book_author);

            //Printing Book_Publications
            printf("\tBOOK PUBLICATIONS : %s\n", bookstore[i].book_publications);

            //Printing Book_Pages
            printf("\tBOOK PAGES : %d\n", bookstore[i].book_pages);

            //Printing Book_Price
            printf("\tBOOK PRICE : %d\n", bookstore[i].book_price);

            //Printing Book_Quantity
            printf("\tBOOK QUANTITY : %d\n", bookstore[i].book_quantity);
        }
    }
    return;
}

//USER-DEFINED FUNCTION TO ADD BOOK TO CART
void add_to_cart()
{
    char book_name_to_add[50];
    printf("\tENTER THE BOOK NAME TO ADD TO CART:  ");
    fflush(stdin);
    gets(book_name_to_add);
    int i=0, flag=0;
    for(i=0; i<count; i++)
    {
        if(strcmp(book_name_to_add,bookstore[i].book_name)==0)
        {
            flag=1;
            cart[cartbooks].books_id=bookstore[i].book_id;
            strcpy(cart[cartbooks].books_name,bookstore[i].book_name);
            strcpy(cart[cartbooks].books_author,bookstore[i].book_author);
            strcpy(cart[cartbooks].books_publications,bookstore[i].book_publications);
            cart[cartbooks].books_pages=bookstore[i].book_pages;
            cart[cartbooks].books_price=bookstore[i].book_price;
            cart[cartbooks].books_quantity=bookstore[i].book_quantity;
            cartbooks++;
            printf("\n\tBOOK ADDED SUCCESSFULLY TO CART\n");
        }
    }
    if(flag==0)
    {
        printf("\tBOOK NOT FOUND WITH THE GIVEN %s BOOK QUANTITY!\n", book_name_to_add);
        printf("\tRETURNING BACK TO THE MAIN MENU!\n");
    }
}

//USER-DEFINED FUNCTION TO VIEW CART
void view_cart()
{
    if(cartbooks==0)
	{
    	printf("\tbookstore IS EMPTY.\n");
    	return;
	}
	else
	{
    	int i=0;

    	//PRINTING TABLE FOR ALL THE BOOKS IN THE CART
    	for(i=0; i<cartbooks; i++)
    	{
        	//Printing S.No.
            printf("\tS.No. : %d\n", i+1);

            //Printing Book_ID
            printf("\tBOOK ID : %d\n", cart[i].books_id);

            //Printing Book_Name
            printf("\tBOOK NAME : %s\n", cart[i].books_name);

            //Printing Book_Author
            printf("\tBOOK AUTHOR : %s\n", cart[i].books_author);

            //Printing Book_Publications
            printf("\tBOOK PUBLICATIONS : %s\n", cart[i].books_publications);

            //Printing Book_Pages
            printf("\tBOOK PAGES : %d\n", cart[i].books_pages);

            //Printing Book_Price
            printf("\tBOOK PRICE : %d\n", cart[i].books_price);

            //Printing Book_Quantity
            printf("\tBOOK QUANTITY : %d\n", cart[i].books_quantity);
    	}
	}
}