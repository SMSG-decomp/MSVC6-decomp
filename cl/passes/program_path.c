char * __cdecl program_path(void)

{
  char **pgmptr;
  
  pgmptr = __p__pgmptr();
  return *pgmptr;
}

