long __cdecl lex_time_now(long *timer)

{
  time_t tVar1;
  
  tVar1 = time((time_t *)timer);
  return (long)tVar1;
}

