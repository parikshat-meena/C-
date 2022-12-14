#include "admin.h"
#include "user.h"

///////////////////////////////////////////////

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	cout<<"\n\t*********************************************************************************************************";
	cout<<"\n\t********************************                                        *********************************";
	cout<<"\n\t********************************   WELCOME TO BANK APPLICATION SYSTEM   *********************************";
	cout<<"\n\t********************************                                        *********************************";
	cout<<"\n\t*********************************************************************************************************";
	
	int ch=0;
	char str[10];
	while(ch!=10)
	{				 
		cout<<"\n\n\t================================          Welcome to Home Page          ================================";
		cout<<"\n\n\t\t1.Admin ";
		cout<<"\n\t\t2.User ";
		cout<<"\n\t\t10.Exit ";
		cout<<"\n\t\tEnter your choice : ";
		cin>>str;
		ch = atoi(str);
		switch(ch)
		{
			case 1://Admin 
				{
					cout<<"\n\n\t++++++++++++++++++++++++++++++++          Welcome To Admin Portal       ++++++++++++++++++++++++++++++";
					char adminId[20] ="pmeena123";
					char adminPassword[20]= "parik";
					char a1[20];
					char p1[20];
					cout<<"\n\n\t\tEnter Admin ID : ";
					cin>>a1;
					cout<<"\t\tEnter Admin Password : ";
					cin>>p1;
					if(!strcmp(adminId,a1) && !strcmp(adminPassword,p1))
					{
					
						int choice=0;
						char str2[20];
						Admin ad;
						cout<<"\n\tWelcome Parikshat!!";
						while(choice!=10)
						{
							cout<<"\n\n\t\t1.Add New Account";
							cout<<"\n\t\t2.Display All Account";
							cout<<"\n\t\t3.Search";
							cout<<"\n\t\t4.Update";
							cout<<"\n\t\t5.Delete";
							cout<<"\n\t\t6.Display All Transactions";
							cout<<"\n\t\t7.Delete All Transactions";
							cout<<"\n\t\t10.Exit";
							cout<<"\n\t\tEnter your choice : ";
							cin>>str2;
							choice = atoi(str2);
							switch(choice)
							{
								case 1://Add New Account
									{
										cout<<"\n\t\tEnter Account_no, Name and Balance ";
										int acc_no;
										char st1[10];
										char name[20];
										double bs;
										char str2[10];
										cin>>st1;
										acc_no = atoi(st1);
										cin>>name;
										cin>>str2;
										bs = atoi(str2);
										if(acc_no == 0||bs ==0)
										{
											cout<<"\n\t\tInvalid Details Filled ";
											break;
										}
										Account a(acc_no,name,bs);
										ad.addAccount(a);
									}
									break;
								case 2://Dispaly All Account
									{
										ad.displayAllAccount();
										break;
									}
								case 3://Search Menu
									{
										int cho=0;
										char str3[20];
										while (cho!=3)
										{
											cout<<"\n\n\t\t1.Search by Account Number";
											cout<<"\n\t\t2.Search by Name";
											cout<<"\n\t\t3.Exit";
											cout<<"\n\t\tEnter your choice : ";
											cin>>str3;
											cho = atoi(str3);
											switch(cho)
											{
												case 1://Search By Account Number
													{
														cout<<"\n\t\tEnter Account No to be searched : ";
														int accNo;
														char s[20];
														
														cin>>s;
														accNo = atoi(s);
														ad.searchByAccNo(accNo);
														break;
														
													}
												case 2://search by name
													{
														char name[20];
														cout<<"\n\t\tEnter Name to be searched : ";
														cin>>name;
														ad.searchByName(name);
														break;	
													}
												case 3:
													{
														
														break;
													}
												default:
													{
														cout<<"\n\t\tInvalid Input";
													}
											}
										}
										break;
									}
								case 4:  //update by admin
									{
										int c=0;
										char c1[20];
										while (c!=3)
										{
											cout<<"\n\n\t\t1.Update by Account Number";
											cout<<"\n\t\t2.Update by Name";
											cout<<"\n\t\t3.Exit";
											cout<<"\n\t\tEnter your choice";
											cin>>c1;
											c = atoi(c1);
											switch(c)
											{
												case 1:  	//update by account number
													{
														cout<<"\n\t\tEnter Account Number : ";
														int accNo;
														char s2[20];
														cin>>s2;
														accNo = atoi(s2);
														ad.updateAcc_no(accNo);
														break;
													}
												case 2:    //update by Name
													{
														cout<<"\n\t\tEnter Name to be updated : ";
														char name[20];
														cin>>name;
														ad.updateName(name);
														break;
													}
												case 3:
													{
														break;
													}
												default:
													{
														cout<<"\n\t\tInvalid Input";
													}
											}
										}
										break;
									}
								case 5:   //delete by admin
									{
										int accno;
										char str[20];
										cout<<"\n\t\tEnter Account Number to Delete Account Permanently: ";
										cin>>str;
										accno = atoi(str);
										ad.deleteByAcc_no(accno);
										break;
									}
								case 6:
									{   // Display Transaction
										ad.displayAllTransaction();
										break;
									}
								case 7:
									{  // Delete All Transaction
										ad.deleteAllTransaction();
										break;
									}
								case 10:
									{
										break;
									}
								default:
									{
										cout<<"\n\t\tInvalid Input";
									}
							}
						}
					}
					else
					{
						cout<<"\n\t\tIncorrect Admin ID or Password";
					}	
					break;
				}
			case 2:   //User 
				{
					int cha=0;
					char s3[20];
					while(cha!=3)
					{  	pass:
						cout<<"\n\n\t++++++++++++++++++++++++++++++++         Welcome to User portal          ++++++++++++++++++++++++++++++++";
						cout<<"\n\n\t\t1.Login";
						cout<<"\n\t\t2.Register";
						cout<<"\n\t\t3.Exit";
						cout<<"\n\t\tEnter your choice : ";
						cin>>s3;
						cha = atoi(s3);
						switch(cha)
						{
							case 1:  //User login 
							{	
								
								char id[20];
								char pass[20];
								cout<<"\n\n\t\tEnter UserId : ";
								cin>>id;
								cout<<"\t\tEnter Password : ";
								cin>>pass;
								User u;
								if(u.checkCredential(id,pass))
								{
									u.displayName(id);
									int choic=0;
									char s4[20];
									Admin a1;
									while(choic!=10)
									{
										cout<<"\n\n\t\t1.View Account Details";
										cout<<"\n\t\t2.Deposit";
										cout<<"\n\t\t3.Withdraw";
										cout<<"\n\t\t4.Transfer";
										cout<<"\n\t\t5.Dislay Transaction History";
										cout<<"\n\t\t6.Change Password";
										cout<<"\n\t\t10.Exit";
										cout<<"\n\t\tEnter your choice : ";
										cin>>s4;
										choic = atoi(s4);
										switch(choic)
										{
											case 1: //View Account Details
												{
													u.viewDetails(id);
													break;
												}
											case 2: //Deposit
												{
													int bal;
													char s5[20];
													cout<<"\n\t\tEnter the Amount to be Deposited : ";
													cin>>s5;
													bal = atoi(s5);
													if(bal==0)
													{
														cout<<"\n\t\tInvalid Amount";
														break;
													}
													u.deposit(bal,id);			
													break;
												}
											case 3: //Withdraw
												{
													int bal;
													char s6[20];
													cout<<"\n\t\tEnter Amount to be withdrawn : ";
													cin>>s6;
													bal = atoi(s6);
													if(bal==0)
													{
														cout<<"\n\t\tInvalid Amount";
														break;
													}
													u.withdraw(bal,id);
													break;
												}
											case 4: //Transfer
												{
													int bal,tAccno;
													char s7[20];
													char s8[20];
													cout<<"\n\t\tEnter Amount to Transfer : ";
													cin>>s7;
													bal = atoi(s7);
													cout<<"\n\t\tEnter Account No For Transfer : ";
													cin>>s8;
													tAccno = atoi(s8);
													if(bal==0)
													{
														cout<<"\n\t\tInvalid Amount";
														break;
													}
													if(tAccno==0)
													{
														cout<<"\n\t\tInvalid Account Number";
														break;
													}
													u.transfer(bal,tAccno,id);
													break;
												}
											case 5: // Display user's transaction
												{
													u.displayTransaction(id);
													break;
												}
											case 6: // Password change
												{
													u.changePassword(id);
													goto pass;
													break;
												
												}
											case 10:
												{
													break;
												}
											default:
												{
													cout<<"\n\t\tInvalid Input";
													break;
												}	
										}
									}	
								}
								else
								{
									cout<<"\n\n\t\tIncorrect UserId or Password";
								}
								break;
							}
							case 2://User Registeration
							{
								Admin ad;
								int aNo;
								char s9[20];
								cout<<"\n\n\t\tEnter your Account Number : ";
								cin>>s9;
								aNo = atoi(s9);
								if(ad.checkAccNo(aNo))
								{
									User u1;
									if( u1.checkRepeatation(aNo))
									{
										cout<<"\n\t\tUser Id Already Exist for this account";
									}
									else
									{
										char userid[20];
										char password[20];
										cout<<"\n\t\tEnter Your user ID : ";
										cin>>userid;
										cout<<"\t\tEnter Your Password : ";
										cin>>password;
										User u(aNo,userid,password);
										u.addUser(u);
									}
								}
								else
								{
									cout<<"\n\n\t\tInvalid Account No";
								}
								break;
							}
							case 3:
								{
									break;
								}
							default:
							{
								cout<<"Invalid Input";
								break;
							}
						}
					}
					break;
				}
			case 10:
				{
					cout<<"\n\n\t================================            Thank You !!!!              ================================";
					break;
				}
			default :
				{
					cout<<"\n\tInvalid Input";
					break;
				}
		}		
	}
	return 0;
}
