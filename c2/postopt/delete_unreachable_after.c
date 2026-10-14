int __fastcall delete_unreachable_after(c2_function *fn,c2_tuple *term)

{
  if (term->next == (c2_tuple *)0x0) {
    return 0;
  }
  halt_baddata();
}

