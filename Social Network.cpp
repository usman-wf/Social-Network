//#include<iostream>
//#include<fstream>
//using namespace std;
//
//class post;
//class facebook;
//class memory;
//class Date;
//class comment;
//class Activity;
//class object;
//
//class helper
//{
//public:
//
//	static int stringlength(const char* str)
//	{
//		int length = 0;
//		for (int i = 0; str[i] != '\0'; i++)
//		{
//			length++;
//		}
//		return length;
//	}
//
//	static void stringcopy(char*& dest,const char*& src)
//	{
//		int length = stringlength(src);
//		for (int i = 0; i < length; i++)
//		{
//			dest[i] = src[i];
//		}
//		dest[length] = '\0';
//
//	}
//
//	static char* getstringfrombuffer(const char* oldArr)
//	{
//		int strLen = stringlength(oldArr);
//		char* str = 0;
//
//		if (strLen > 0)
//		{
//			str = new char[strLen+1];
//			stringcopy(str, oldArr);
//		}
//		return str;
//	}
//
//	static bool stringCompare(const char* str1, const char* str2)
//	{
//		int count = 0;
//		if (stringlength(str1) == stringlength(str2))
//		{
//			for (int i = 0; i < stringlength(str1); i++)
//			{
//				if (str1[i] == str2[i])
//				{
//					count++;
//				}
//			}
//			if (count == stringlength(str1))
//			{
//				return true;
//			}
//		}
//		else
//		{
//			return false;
//		}
//	}
//
//	static char* IntToString(int id)
//	{
//		char *ptr = new char[3];   ////i to a, a to i, can also be used
//		int temp = 0;
//		temp = id / 10;
//		ptr[0] = temp + '0';
//		temp = id % 10;
//		ptr[1] = temp + '0';
//		ptr[2] = '\0';
//		return ptr;
//	}
//
//    static void StringConcatenate(char*&str1 ,char*&str2 )
//    {
//	int length1 = stringlength(str1);
//	int length2 = stringlength(str2);
//	int size = length1 + length2;
//	char* temp = new char[size+1];
//	int n = 0;
//	for (int i = 0; i < size; i++)
//	{
//		temp[i] = str1[i];
//
//		if (i==length1)
//		{
//			while (n < length2)
//			{
//				temp[i] = str2[n];
//				i++, n++;
//			}
//		}
//	}
//	temp[size] = '\0';
//	str1 = getstringfrombuffer(temp);
//	delete[] temp;
//	temp = 0;
//}
//
//};
//
//class Date
//{
//private:
//
//	int date;
//	int month;
//	int year;
//public:
//	static Date CurrentDate;
//	
//	void printdate()
//	{
//		cout <<"(" << date << "/" << month << "/" << year <<")"<< endl;
//	}
//
//	Date()
//	{
//		date = CurrentDate.date;
//		month = CurrentDate.month;
//		year = CurrentDate.year;
//	}
//
//	static void setCurrentDate(int d, int m, int y)
//	{
//		CurrentDate.date = d;
//		CurrentDate.month = m;
//		CurrentDate.year = y;
//	}
//
//	void ReadFromFile(fstream& obj)
//	{
//		obj >> date;
//		obj >> month;
//		obj >> year;
//	}
//
//	int GetMemoryDifference(Date org)
//	{
//		int difference = 0;
//		difference = year - org.year;
//		return difference;
//	}
//
//	int GetDifference()
//	{
//		int difference = 0;
//		difference = CurrentDate.year - year;
//		return difference;
//	}
//
//	bool IsLatest()
//	{
//		bool check = false;
//		if (month == CurrentDate.month && year == CurrentDate.year)
//		{
//			if (date == CurrentDate.date || CurrentDate.date - 1 == date)
//			{
//				return true;
//			}
//		}
//		return false;
//	}
//
//	bool CompareDayAndMonth()
//	{
//		return (date == CurrentDate.date && month == CurrentDate.month && year != CurrentDate.year);
//	}
//
//	int getdate()
//	{
//		return date;
//	}
//	int getmonth()
//	{
//		return month;
//	}
//	int getyear()
//	{
//		return year;
//	}
//	void setdate(int d)
//	{
//		date = d;
//	}
//	void setmonth(int m)
//	{
//		month = m;
//	}
//	void setyear(int y)
//	{
//		year = y;
//	}
//	
//};
//
//Date Date::CurrentDate;
//
//class Activity
//{
//private:
//	char* type;
//	char* value;
//public:
//	Activity()
//	{
//		type = 0;
//		value = 0;
//	}
//	~Activity();
//
//	void ReadFromFile(fstream&obj)
//	{
//		char buffer[50];
//		obj >> buffer;
//		type = helper::getstringfrombuffer(buffer);
//		switch (*type)
//		{
//		case '1':
//			type = helper::getstringfrombuffer("feeling");
//			break;
//		case '2':
//			type = helper::getstringfrombuffer("thinking about");
//			break;
//		case '3':
//			type = helper::getstringfrombuffer("making");
//			break;
//		case '4':
//			type = helper::getstringfrombuffer("celebrating");
//			break;
//			
//		default:
//			break;
//		}	
//		obj.getline(buffer,50);
//		value = helper::getstringfrombuffer(buffer);
//	}
//
//	char* getvalue()
//	{
//		return value;
//	}
//
//	char* gettype()
//	{
//		return type;
//	}
//
//	void Print()
//	{
//		cout << " is " << type << " " << value;
//	}
//	
//};
//
//Activity::~Activity()
//{
//	if (type != 0)
//	{
//		delete type;
//	}
//
//	if (value != 0)
//	{
//		delete value;
//	}
//}
//
//class object
//{
//private:
//	 char* ID;
//	static int postcounter ;
//public:
//
//	virtual void Register(post* ptr) = 0;
//	object()
//	{
//		ID = 0;
//	}
//	virtual void setID(char*id)
//	{
//		ID = helper::getstringfrombuffer(id);
//	}
//    virtual	char* getID()
//	{
//		return ID;
//	}
//	virtual void printname() = 0; 
//	virtual void print() = 0;
//	virtual ~object()
//	{
//
//	}
//};
//
//class comment
//{
//private:
//	char* ID;
//	object* CommentBy;
//	char* text;
//	static int totalComments;
//	static int incrementComments;
//
//public:
//	comment()
//	{
//		ID = 0;
//		CommentBy = 0;
//		text = 0;
//		totalComments++;
//	}
//
//	int getcommentid()
//	{
//		return totalComments + incrementComments;
//	}
//
//	comment(object* CurrentUser, const char* str)
//	{
//		incrementComments++;
//		CommentBy = CurrentUser;
//		text = helper::getstringfrombuffer(str);
//		int idNum = getcommentid();
//		char* ptr1=new char[2];
//		ptr1[0] = 'c';
//		ptr1[1] = '\0';
//		char* ptr2 = helper::IntToString(idNum);
//		helper::StringConcatenate(ptr1, ptr2);
//		ID = ptr1;
//	}
//
//	~comment();
//
//	void SetValues(char*id,const char*txt,object* cmntby)
//	{ 
//		ID = helper::getstringfrombuffer(id);
//		text = helper::getstringfrombuffer(txt);
//		CommentBy = cmntby;
//	}	
//
//	void View()
//	{
//		cout << "\t\t";
//		CommentBy->printname();
//		cout<<" wrote : " << text ;
//	}
//};
//int comment::totalComments = 0;
//int comment::incrementComments = 0;
//
//comment::~comment()
//{
//	if (ID != 0)
//	{
//		delete[] ID;
//	}
//
//	if (text != 0)
//	{
//		delete[] text;
//	}
//
//}
//
//
//class post
//{
//protected:
//	char* ID;
//	Date sharedDate;
//	char* text;
//	object* sharedBy;
//	Activity* activity;
//	object** LikedBy;
//	comment** comments;
//	int commentcounter = 0;
//	int likecounter = 0;
//	int counter = 0;
//public:
//
//	post(char* txt, object* shared);
//	~post();
//
//	bool IsMemory()
//	{
//		if (sharedDate.CompareDayAndMonth())
//		{
//			return true;
//		}
//		return false;
//	}
//
//	void PrintMemory()
//	{
//		cout << "On This Day \n" << sharedDate.GetDifference() << " Years Ago Today ";
//		Print(true,false);
//	}
//
//	virtual void Print(bool flag , bool date )
//	{
//		////bool check=flag;
//		cout << "---";
//		sharedBy->printname();
//		if (activity)
//		{
//			activity->Print();
//		}
//		else
//		{
//			cout << " shared ";
//		}	
//		cout << endl << "   \"" << text << "\"";
//		if(date==true)
//		{
//			sharedDate.printdate();
//		}
//		cout << endl;
//		if(flag==true)
//		{
//			for (int i = 0; i < commentcounter; i++)
//			{
//				comments[i]->View();
//				cout << endl;
//			}
//		}
//	}
//
//	post()
//	{
//		text = 0;
//		sharedBy = 0;
//		activity = 0;
//		LikedBy = 0;
//		comments = 0;
//		ID = 0;
//	}
//
//	char* getID()
//	{
//		return ID;
//	}
//
//	void LoadDataFromFile(fstream& obj)
//	{
//		int type = 0;
//		char buffer[100];
//		obj >> type;
//		obj >> buffer;
//		ID = helper::getstringfrombuffer(buffer);
//		sharedDate.ReadFromFile(obj);	
//		obj.getline(buffer, 100);
//		if (buffer[0] == '\t' || buffer[0] == '\0')
//		{
//			obj.getline(buffer, 100);
//		}
//		text = helper::getstringfrombuffer(buffer);
//		if (type == 2)
//		{
//			activity = new Activity;
//			activity->ReadFromFile(obj);
//		}
//	}
//
//	void AddComment(comment* ptr)
//	{
//		if (!comments)
//		{
//			comments = new comment * [10];
//		}
//
//		if (commentcounter < 10)
//		{
//			comments[commentcounter] = ptr;
//
//			if (ptr != 0)
//			{
//				commentcounter++;
//			}
//		}
//		else(cout << "\n No space for new comment\n");
//	}
//
//	void SetSharedBy(object*&ptr)
//	{
//		if (ptr != 0)
//		{
//			sharedBy = ptr;
//		}
//	}
//
//	void SetLikedBy(object* ptr)
//	{
//		if (!LikedBy)
//		{
//			LikedBy = new object * [10];
//		}
//		if (likecounter < 10)
//		{
//
//			LikedBy[likecounter] = ptr;
//
//			if (ptr != 0)
//			{
//				likecounter++;
//
//			}
//		}
//		else(cout << "\n No space for new comment\n");		
//	}
//
//	bool checkDate()
//	{
//		if (sharedDate.IsLatest())
//		{
//			return true;
//		}
//		else 
//		{
//			return false;
//		}
//	}
//
//	void printSharedDate()
//	{
//		sharedDate.printdate();
//	}
//
//	void Likes()
//	{
//		for (int i = 0; i < likecounter; i++)
//		{
//			LikedBy[i]->print();	
//		}
//	}
//
//	Date getsharedDate()
//	{
//		return sharedDate;
//	}
//
//	Activity* getActivity()
//	{
//		if(activity!=NULL)
//		{
//			return activity;
//		}
//		return NULL;
//	}
//
//};
//
//post::~post()
//{
//	////cout << "\n POST Destructor \n";
//	if (ID != 0)
//	{
//		delete[] ID;
//		ID = 0;
//	}
//
//	if (text != 0)
//	{
//		delete[] text;
//		text = 0;
//	}
//
//	if (activity != 0)
//	{
//		delete activity;
//		
//	}
//
//	if (LikedBy != 0)
//	{
//		delete LikedBy;
//		
//	}
//
//	if (comments != 0)
//	{
//		//cout << "comments destructor called\n";
//		for (int i = 0; i < commentcounter; i++)
//		{
//		delete comments[i];			
//		}
//		delete comments;
//	}
//	comments = 0;
//
//}
//
//class memory : public post
//{
//private:
//	post* original;
//public:
//	memory(post*& oldPost, char* text, object* userptr) :post(text, userptr)
//	{
//		original = oldPost;
//	}
//	void Print(bool flag = false, bool date = false);
//};
//
//class page : public object
//{
//private:
//	char* id;
//	char* title;
//	post** timeline;
//	int postcounter = 0;
//public:
//	page()
//	{
//		id = 0;
//		title = 0;
//		timeline = 0;
//	}
//
//	~page();
//
//	void LoadPages(fstream& obj)
//	{
//		char buffer[50];
//		obj >> buffer;
//		id = helper::getstringfrombuffer(buffer);
//		obj.getline(buffer, 50);
//		title = helper::getstringfrombuffer(buffer);
//	}
//
//	char* getId()
//	{
//		return id;
//	}
//
//	void printname()
//	{
//		cout << title;
//	}
//
//	void print()
//	{
//		cout <<id<< title << endl;
//	}
//
//	void Register(post* ptr)
//	{
//		if (!timeline)
//		{
//			timeline = new post * [10];
//		}
//
//		timeline[postcounter] = ptr;
//
//		if (ptr != 0)
//		{
//			postcounter++;
//		}
//	}
//
//	void viewTimeline()
//	{
//		if (postcounter > 0)
//		{
//			for (int i = 0; i < postcounter; i++)
//			{
//				timeline[i]->Print(true,true);
//			}
//		}
//		else
//		{
//			cout << "\n No available posts for selected user \n";
//		}
//	}
//
//	void PageLatest()
//	{
//		for (int i = 0; i < postcounter; i++)
//		{
//			if (timeline[i]->checkDate())
//			{
//				timeline[i]->Print(true,false);
//			}
//
//		}
//	}
//
//	char* gettitle()
//	{
//		return title;
//	}
//};
//
//page::~page()
//{
//	if(id!=0)
//	{
//		delete[] id;
//		
//	}
//	if(title!=0)
//	{
//		delete[] title;
//		
//	}
//	for (int i = 0; i < postcounter; i++)
//	{
//		if (timeline[i])
//		{
//			delete timeline[i];
//			timeline[i] = NULL;
//		}
//
//	}
//	delete[] timeline;
//	timeline = 0;
//}
//
//class user : public object
//{
//private:
//	char* id;
//	char* fname;
//	char* lname;
//	page** likedpages;
//	user** friendlist;
//	post** timeline;
//	int likedpagescounter;
//	int friendcounter;
//	int postcounter;
//	int likelimit = 10;
//	int commentlimit = 10;
//	static int index;
//	
//public:
//
//	~user();
//
//	user()
//	{
//		id = 0;
//		fname = 0;
//		lname = 0;
//		likedpages = 0;
//		friendlist = 0;
//		timeline = 0;
//		likedpagescounter = 0;
//		friendcounter = 0;	
//		postcounter = 0;
//	}
//
//	void Register(page*& ptr)
//	{
//		if(!likedpages)
//		{
//			likedpages = new page * [10];
//		}
//
//		likedpages[likedpagescounter] = ptr;
//
//		if (ptr!= 0)		
//		{			
//			likedpagescounter++;
//		}
//	}
//
//	void Register(user*& ptr)
//	{
//		if (!friendlist)
//		{
//			friendlist = new user * [10];
//		}
//
//		friendlist[friendcounter] = ptr;
//
//		if (ptr != 0)
//		{			
//			friendcounter++;
//		}
//	}
//
//	void Register(post * ptr)
//	{
//		if (!timeline)
//		{
//			timeline = new post * [10];
//		}
//
//		timeline[postcounter] = ptr;
//
//		if (ptr != 0)
//		{
//			postcounter++;
//		}
//	}
//
//	void LoadUsers(fstream& obj)
//	{
//		char buffer[20];
//		obj >> buffer;
//		id = helper::getstringfrombuffer(buffer);
//		obj >> buffer;
//		fname = helper::getstringfrombuffer(buffer);
//		obj >> buffer;
//		lname = helper::getstringfrombuffer(buffer);
//	}
//
//	void print()
//	{
//		cout << id << " " <<fname << " " <<lname << endl;
//
//	}
//
//	void printname()
//	{
//		cout << fname << " " << lname;
//	}
//
//	void viewfriendslist()
//	{
//		for (int i = 0; i < friendcounter; i++)
//		{
//			friendlist[i]->print();
//		}
//	}
//
//	void viewlikedpages()
//	{
//		
//		for (int i = 0; i < likedpagescounter; i++)
//		{
//		 likedpages[i]->print();		
//		}
//	}
//
//	char* getid()
//	{
//		return id;
//	}
//
//	char* getfname()
//	{
//		return fname;
//	}
//
//	char* getlname()
//	{
//		return lname;
//	}
//
//	void viewTimeline()
//	{
//		if(postcounter > 0)
//		{
//			for (int i = 0; i < postcounter; i++)
//			{				
//				timeline[i]->Print(true,true);
//			}
//		}
//		else
//		{
//			cout << "\n No available posts for selected user \n"; 
//		}
//	}
//
//	void OldPosts()
//	{
//		for (int i = 0; i < postcounter; i++)
//		{
//			if (timeline[i]->IsMemory())
//			{			
//				timeline[i]->PrintMemory();
//			}
//		}
//	}
//
//	void UserLatest()
//	{
//		for (int i = 0; i < postcounter; i++)
//		{			
//			if (timeline[i]->checkDate())
//			{
//				timeline[i]->Print(true,false);				
//			}
//		}
//	}
//
//	void Home()
//	{
//		for (int i = 0; i < friendcounter; i++)
//		{			
//  		   friendlist[i]->UserLatest();
//		}
//
//		for (int i = 0; i < likedpagescounter; i++)
//		{
//			likedpages[i]->PageLatest();
//		}
//	}	
//
//	void ViewUser()
//	{
//		cout << endl << id << " " << fname << " " << lname << endl;
//	}
//
//};
//
//user::~user()
//{
//	if(id!=0)
//	{
//		delete[] id;
//	}
//	if (fname != 0)
//	{
//		delete[] fname;
//	}
//	if (lname != 0)
//	{
//		delete[] lname;
//	}
//	if (likedpages != 0)
//	{
//		delete[] likedpages;
//	}
//	if (friendlist != 0)
//	{
//		delete[] friendlist;
//	}
//
//	for (int i = 0; i < postcounter; i++)
//	{
//	 if (timeline[i])
//	 {
//		delete timeline[i];
//		timeline[i] = 0;
//	 }
//
//	}
//	
//    delete[] timeline;
//	timeline = 0;
//
//}
//
//int user::index = 0;
//
//class facebook
//{
//private:
//	user* currentuser;
//	page** pages;
//	user** users;
//	post** posts;
//
//	static int pagecount;
//	static int totalpages;
//	static int totalusers;
//	static int totalposts;
//	static int totallikes;
//	static int incrementPost;
//
//public:
//	facebook()
//	{
//		currentuser = 0;
//		pages = 0;
//		users = 0;
//		posts = 0;
//	}
//	
//	page* SearchPagesById(const char* str)
//	{
//		page* found = 0;
//		bool checkDate = false;
//		//////cout << endl << totalpages << endl;
//		for (int i = 0; i < totalpages; i++)
//		{
//			int match1 = 0;
//			int match2 = 0;
//			char* temp = pages[i]->getId();
//			if (str[match1] == temp[0])
//			{
//				while (str[match1] != '\0' && temp[match2] != '\0')
//				{
//					if (str[match1++] == temp[match2++])
//					{
//						checkDate = true;
//					}
//					else
//					{
//						checkDate = false;
//						continue;
//					}
//				}
//			}
//			if (checkDate == true)
//			{
//				found = pages[i];
//				return found;
//			}
//		}
//		return found;
//	}
//
//	user* SearchUsersById(const char* str)
//	{
//		user* found = 0;
//		bool check = false;
//	
//		for (int i = 0; i < totalusers; i++)
//		{
//			char* temp = users[i]->getid();
//			int match1 = 0;
//			int match2 = 0;
//			int counter = 0;
//			int length = 0;
//			if (temp[match1] == str[match2])
//			{
//				length = helper::stringlength(str);
//				while (temp[match1] != '\0' && str[match2] != '\0')
//				{
//					if (temp[match1++] == str[match2++])
//					{
//						counter++;
//						check = true;
//					}
//					else
//					{
//						check = false;
//						continue;
//					}
//				}
//			}
//
//			if (counter == length)
//			{
//				found = users[i];
//				return found;
//			}
//		}
//		return found;
//	}
//
//	post* SearchPostsById(const char* str)
//	{
//		post* found = 0;
//		bool check = false;
//		/////cout << endl << totalposts << endl;
//		for (int i = 0; i < totalposts; i++)
//		{
//			int n = 0;
//			int match1 = 0;
//			int match2 = 0;
//			int length = helper::stringlength(str);
//
//			char* temp = posts[i]->getID();
//			if (str[match1] == temp[match2])
//			{
//				while (str[n]!='\0')
//				{
//					if (str[match1++] == temp[match2++])
//					{
//						check = true;
//					}
//					else
//					{
//						check = false;
//						break;
//					}
//					n++;
//				}
//			}
//			if (check == true)
//			{
//				found = posts[i];
//				return found;
//			}
//		}
//	  return found;
//	}	
//
//	object* SearchObjectById(char* str)
//	{
//		object *found=0;
//		if(str[0]=='u')
//		{
//			found = SearchUsersById(str);
//		}
//		if (found != 0)
//		{
//			return found;
//	    }
//		else if(str[0] == 'p')
//		{
//			found = SearchPagesById(str);
//		}
//		if (found != 0)
//		{
//			return found;
//		}
//		return found;
//
//	}
//
//	void LoadPagesFromFile()
//	{
//		fstream obj;
//		int total = 0;
//		pages = 0;
//		obj.open("Pages.txt", ios::in);
//		obj >> total;
//		totalpages = total;
//		///////cout << total;
//		pages = new page * [total];
//		for (int i = 0; i < total; i++)
//		{
//			pages[i] = new page;
//			pages[i]->LoadPages(obj);
//			//delete pages[i];
//		}
//		obj.close();
//	}
//
//	void LoadUsersFromFile()
//	{
//
//		fstream obj;
//		int total = 0;
//		int numpage = 0;
//		int numfriends = 0;
//		obj.open("Users.txt", ios::in);
//		obj >> total;
//		totalusers = total;
//		users = new user * [total];
//		int counter = 0;
//		char*** temp = new char** [total];
//		for (int i = 0; i < total; i++)
//		{
//			int count = 0;
//			int length = 0;
//			int size = 0;
//			int condition = 0;
//			char buffer[20];
//			char* str = 0;
//			users[i] = new user;
//			users[i]->LoadUsers(obj);
//			page* ptr = 0;					
//			temp[i] = new char* [10];
//			for (int j = 0; j < 10; j++) //// 10 here denotes max friends will be 10
//			{
//				obj >> buffer;
//				if (buffer[0] == '-')
//				{
//					count++;
//					while (count == 1)
//					{
//						obj >> buffer;
//						if (buffer[0] == '-')
//						{
//							count++;
//							break;
//						}
//						else
//						{
//
//							ptr = SearchPagesById(buffer);
//							users[i]->Register(ptr);
//							numpage++;
//						}
//
//						if (count == 2)
//						{
//							ptr = 0;
//							users[i]->Register(ptr);
//							obj >> buffer;
//						}
//					}
//				}
//				else
//				{
//					temp[i][j] = helper::getstringfrombuffer(buffer);
//					counter++;
//				}
//
//				if (count == 2)
//				{
//					count = 0;
//					temp[i][counter] = NULL;
//					counter = 0;
//					break;
//
//				}
//
//			}
//
//		}
//		obj.close();
//
//		user* ptr = 0;
//		int count = 0;
//		for (int i = 0; i < totalusers; i++)
//		{
//			int j = 0;
//			while (temp[i][j] != NULL)
//			{
//				ptr = SearchUsersById(temp[i][j]);
//				users[i]->Register(ptr);
//				numfriends++;
//				j++;
//			}
//			ptr = 0;
//			users[i]->Register(ptr);
//			count++;
//			numfriends = 0;
//		}
//
//		for (int i = 0; i < totalusers; i++)
//		{
//			delete[] temp[i];
//			temp[i] = 0;
//		}
//		delete[] temp;
//		temp = 0;
//	}
//
//	void LoadPostsFromFile()
//	{
//		char* check;
//		fstream obj;
//		int total = 0;
//		posts = 0;
//		char buffer[100];
//		obj.open("Posts.txt", ios::in);
//		obj >> total;
//		totalposts = total;
//		posts = new post * [total];
//		for (int i = 0; i < total; i++)
//		{
//			posts[i] = new post;
//			posts[i]->LoadDataFromFile(obj);
//			obj >> buffer;
//			object* sharedby = SearchObjectById(buffer);
//			check = helper::getstringfrombuffer(buffer);
//			object* objPtr = 0;
//			if (buffer[0] == 'u')//////////////
//			{
//				objPtr = SearchUsersById(check);
//			}
//			else if (check[0] == 'p')
//			{
//				objPtr = SearchPagesById(check);
//			}
//			objPtr->Register(posts[i]);
//			posts[i]->SetSharedBy(sharedby);
//			
//			int n = 0;
//			obj >> buffer;
//			while (buffer[0] != '-')
//			{				
//				object* likedby = SearchObjectById(buffer);			
//				posts[i]->SetLikedBy(likedby);
//				n++;
//				obj >> buffer;
//			}
//			totallikes = n;
//			
//		}
//		obj.close();
//	}
//
//	void LoadCommentsFromFile()
//	{
//		fstream obj;
//		int total = 0;
//		char* id = 0;
//		char* commentBy = 0;
//		char* text = 0;
//		obj.open("Comments.txt", ios::in);
//		obj >> total;		
//		char buffer[100];
//		for (int i = 0; i < total; i++)
//		{
//			comment* commentPtr = new comment;
//			obj >> buffer;
//			id = helper::getstringfrombuffer(buffer);
//			obj >> buffer;
//			post* postPtr = SearchPostsById(buffer);
//			postPtr->AddComment(commentPtr);
//			obj >> buffer;
//			commentBy = helper::getstringfrombuffer(buffer);
//			object* commentby = SearchObjectById(commentBy);
//			obj.getline(buffer,100);
//			text = helper::getstringfrombuffer(buffer);
//			commentPtr->SetValues(id, text, commentby);
//		}
//		obj.close();
//	}
//	
//    void Load()
//    {
//	LoadPagesFromFile();
//	LoadUsersFromFile();
//	LoadPostsFromFile();
//	LoadCommentsFromFile();   
//	}
//
//	void  viewLikes(const char*str)
//	{
//	 post *ptr = SearchPostsById(str);
//	 ptr->Likes();
//	}
//
//	void viewpost(const char* str)
//	{
//		post* ptr = SearchPostsById(str);
//		if (ptr)
//		{
//			ptr->Print(true, true);
//		}
//	}
//
//	void likepost(const char* str)
//	{
//		post* ptr = SearchPostsById(str);
//		if (ptr)
//		{
//			ptr->SetLikedBy(getcurrentuser());
//		}
//	}
//
//    void Run();
//
//   user* getcurrentuser()
//	{
//		return currentuser;
//	}
//
//   char* getcurrentuserid()
//   {
//	   return currentuser->getid();
//   }
//
//   static int GetPostNum()
//   {	  
//	   return ++totalposts ;
//   }
//
//   void addcomment(const char* str, const char* cmt,object*CurrentUser)
//   {
//	   post* ptr = SearchPostsById(str);
//	   comment* comnt = new comment(CurrentUser,cmt);  	 
//	   ptr->AddComment(comnt);	  
//   }
//   
//   void PrintDate()
//   {  
//	   Date temp;
//	   temp.printdate();
//   }
//
//   void SeeMemories()
//   {
//	   cout << endl << "We hope you enjoy looking back and sharing your memories on Facebook,";
//	   cout << " from the most recent to those long ago."<<endl<<endl;
//	   currentuser->OldPosts();
//   }
//
//   post** ExtendArray(int counter)
//   {	  
//	   post** temp = new post * [counter];
//	   for (int i = 0; i < counter-1; i++)
//	   {
//		   temp[i] = new post;
//		   temp[i] = posts[i];
//	   }
//	   return temp;
//   }
//
//   void Memory(const char* str, const char* txt, object* currentUser)
//   {
//	   int counter = GetPostNum();
//	   post** temp = ExtendArray(counter);
//	   post* ptr = SearchPostsById(str);
//	   char* text = helper::getstringfrombuffer(txt);
//	   temp[counter-1] = new memory(ptr, text, currentUser);
//	   currentUser->Register(temp[counter-1]);
//	   posts = new post * [counter];
//	   for (int j = 0; j < counter; j++)
//	   {
//		   posts[j] = temp[j];
//	   }
//	  
//   }
//	
//	~facebook();
//};
//
//facebook::~facebook()
//{
//	if (pages != 0)
//	{
//		//cout << "pages destructor called\n";
//		for (int i = 0; i < totalpages; i++)
//		{
//			if (pages[i] != 0)
//			{
//				delete pages[i];
//			}			
//		}
//		delete pages;
//	}
//	pages = 0;
//
//	if (users != 0)
//	{
//		//cout << "users destructor called\n";
//		for (int i = 0; i < totalusers; i++)
//		{
//			if (users[i] != 0)
//			{
//				delete users[i];
//			}
//		}
//		delete users;
//	}
//	users = 0;
//
//	if(posts!=0)
//	{
//		delete posts;
//		posts = 0;
//	}
//
//	currentuser = 0;
//}
//
//int facebook::totalusers = 0;
//int facebook::totalpages = 0;
//int facebook::pagecount = 0;
//int facebook::totalposts = 0;
//int facebook::totallikes = 0;
//int object::postcounter = 0;
//int facebook::incrementPost = 0;
//
//void facebook::Run()
//{
//	Date::setCurrentDate(15, 11, 2017);
//	cout << "Command:\tSet current System Date 15 11 2017 \n";
//	cout << "System Date:\t";
//	PrintDate();
//	cout << "Command:\tSet current user \"u7\" \n";
//	currentuser = SearchUsersById("u3");
//	if (currentuser)
//	{
//		currentuser->printname();
//		cout << " successfully set as Current User\n";
//		cout << endl << endl;
//		cout << "Command:\tView Friends List \n";
//		cout << "-----------------------------------------------------------------------------------------\n";
//		currentuser->printname();
//		cout << "-Friend List\n";
//		currentuser->viewfriendslist();
//		cout << endl << endl;
//		cout << "Command:\tView Liked Pages\n";
//		cout << "-----------------------------------------------------------------------------------------\n";
//		currentuser->printname();
//		cout << "-Liked Pages\n\n";
//		currentuser->viewlikedpages();
//		cout << "-----------------------------------------------------------------------------------------\n";
//		cout << endl << endl;
//		cout << "Command:\tView Home \n";
//		cout << "-----------------------------------------------------------------------------------------\n";
//		currentuser->printname();
//		cout << "-HomePage\n\n";
//		currentuser->Home();
//		cout << endl << endl;
//		cout << "Command:\tView Timeline \n";
//		cout << "-----------------------------------------------------------------------------------------\n";
//		currentuser->printname();
//		cout << "-TimeLine\n\n";
//		currentuser->viewTimeline();
//		cout << "-----------------------------------------------------------------------------------------\n";
//		cout << "Command:\tView LikedList (post5) \n";
//		viewLikes("post5");
//		cout << "-----------------------------------------------------------------------------------------\n";
//		cout << "Command:\tView LikedList (post5) \n";
//		likepost("post5");
//		viewLikes("post5");
//		cout << "-----------------------------------------------------------------------------------------\n";
//		cout << "Command:\tPost Comment(post4,Good Luck For your Result)  \n";
//		addcomment("post4", "Good Luck For your Result", currentuser);
//		cout << "Command:\tViewPost(post4)\n";
//		viewpost("post4");
//		cout << "\n-----------------------------------------------------------------------------------------\n";
//		cout << "Command:\tPost Comment(post8,Thanks For The wishes)  \n";
//		addcomment("post8", "Thanks For The wishes", currentuser);
//		viewpost("post8");
//		cout << "\n-----------------------------------------------------------------------------------------\n";
//		cout << "Command:\tSee Your Memories()\n";
//		SeeMemories();
//		cout << "\n-----------------------------------------------------------------------------------------\n";
//		cout << "Command:\tShare Memory(post10,Never thought I will be specialist in this field...) \n";
//		Memory("post10", "Never thought I will be specialist in this field...", currentuser);
//		cout << "Command:\tView Timeline \n";
//		currentuser->printname();
//		cout << "-TimeLine\n\n";
//		currentuser->viewTimeline();
//	}
//	
//	cout << "\n-----------------------------------------------------------------------------------------\n";
//	cout << "Command:\tView Page(\"p1\" ) \n";
//	page* currentpage = SearchPagesById("p1");
//	if(currentpage)
//	{
//		currentpage->viewTimeline();
//		currentpage = 0;
//	}
//	cout << "\n-----------------------------------------------------------------------------------------\n";
//	cout << "Command:\tSet Current User (\"u11\") \n";
//	currentuser = SearchUsersById("u11");
//
//	if(currentuser)
//	{
//		currentuser->printname();
//		cout << " successfully set as Current User\n";
//		cout << "Command:\tView Home\n";
//		currentuser->printname();
//		cout << "-HomePage\n\n";
//		currentuser->Home();
//		cout << "Command:\tView Timeline \n";
//		cout << "-----------------------------------------------------------------------------------------\n";
//		currentuser->printname();
//		cout << "-TimeLine\n\n";
//		currentuser->viewTimeline();
//	}
//
//	////addcomment("post13", "This Comment is added on new post", currentuser);
//	////cout << "\nCommand:\tViewPost(post13)";
//	////viewpost("post13");//this is extra function
//}
//
//post::post(char* txt, object* shared) : sharedDate(Date::CurrentDate)
//{
//	sharedBy = shared;
//	text = txt;
//	sharedDate = Date::CurrentDate;
//	//Create ID here
//	int id = facebook::GetPostNum() - 1;
//	char stri[5] = { 'p','o','s','t','\0' };
//	char* ptr1 = stri;
//	char* ptr2 = helper::IntToString(id);
//	helper::StringConcatenate(ptr1, ptr2);
//	ID = ptr1;	
//}
//
//void memory::Print(bool flag, bool date)
//{
//	cout << endl;
//	cout << "~~~";
//	sharedBy->printname();
//	cout << " shared a memory ~~~";
//	sharedDate.printdate();
//	cout<< text << endl;
//	cout<<"\t(" << sharedDate.GetMemoryDifference(original->getsharedDate());
//	cout << " Years Ago) \n";
//	if(commentcounter>0)
//	{
//		for (int i = 0; i < commentcounter; i++)
//		{
//			comments[i]->View();
//			cout << endl;
//		}
//	}
//	original->Print(flag,date);
//}
//
//int main()
//{
//	facebook fb;
//	fb.Load();
//    fb.Run();
//
//	//system("pause");
//	return 0;
//}