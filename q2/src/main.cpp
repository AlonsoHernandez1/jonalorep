//********* Copyright © Alonso Hernandez & Jonathon Bell. All rights reserved.
//*
//*
//*  Version : $Header:$
//*
//*
//*  Purpose :
//*
//*
//*  Comments: This file uses a tab size of 2 spaces.
//*
//*
//****************************************************************************

#include <iostream>
#include <cstring>
#include "DocumentRepositoryProcessor.h"

//****************************************************************************

int main(int argc, const char* argv[])
{
  if(argc < 2)
  {
    std::cout<<"usage"<<std::endl;
    return 1;
  }    
  for (int i=1;i!=argc;++i )
  {
    if (strcmp(argv[i], "--index") == 0 )
    {
        //set index mode
        continue;
    }
    if (strcmp(argv[i], "--query") == 0 )
    {
        //set query mode
        continue;
    }
    std::cout << "bad argument: wanted one of {--index, --query} but got  " <<argv[i]<< std::endl;
    return 1;
  }

  DocumentRepositoryProcessor docRepoProcessor("c:\\Users\\Alon\\Downloads\\wikipedia" , "../etc/stopwords.txt");
  docRepoProcessor.process();
  std::cout << "hello alonso " << std::endl;

  return 0;
}

//****************************************************************************
