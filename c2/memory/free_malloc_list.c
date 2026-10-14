void __fastcall free_malloc_list(c2_link *p)

{
  c2_link *pcVar1;
  
  while (p != (c2_link *)0x0) {
    pcVar1 = p->next;
    free(p);
    p = pcVar1;
  }
  return;
}

