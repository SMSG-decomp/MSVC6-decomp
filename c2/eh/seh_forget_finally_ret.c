c2_seh_try_scope * __fastcall seh_forget_finally_ret(c2_tuple *t)

{
  c2_seh_try_scope *pcVar1;
  
  for (pcVar1 = g_seh_try_records; (pcVar1->kind != 2 || (pcVar1->finally_ret != t));
      pcVar1 = pcVar1->next) {
  }
  pcVar1->finally_ret = (c2_tuple *)0x0;
  return pcVar1;
}

