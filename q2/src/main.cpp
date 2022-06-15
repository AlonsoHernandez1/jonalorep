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

//****************************************************************************

enum Action
{
  a_tokenize,
  a_index,
  a_query,
} g_action = a_tokenize;


int main(int argc, const char* argv[])
{
  if (argc < 2)
  {
    std::cout << "usage: "
              << argv[0] << "[options] <data-dir> <stopwords.txt>\n"
              << "options:\n"
              << "\t--index \n"
              << "\t--query \n"
              << std::endl;
    return 0;
  }

  for (auto i = 1; i != argc; ++i)
  {
    if (strcmp(argv[i], "--tokenize") == 0)
    {
      g_action = a_tokenize;
      continue;
    }

    if (strcmp(argv[i], "--index") == 0)
    {
      g_action = a_index;
      continue;
    }

    if (strcmp(argv[i], "--query") == 0)
    {
      g_action = a_query;
      continue;
    }

    std::cout << "bad option: wanted one of {--index, --query} but got '"
              << argv[i] << "'" << std::endl;
    return 1;
  }

  std::cout << "hello alonso " << std::endl;

  return 0;
}

//****************************************************************************
