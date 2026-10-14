c2_cxx_try_block * __fastcall eh_next_unhandled_object(c2_cxx_try_block *prev)

{
  c2_cxx_try_block *pcVar1;
  
  pcVar1 = g_eh_trymap_list;
  if (prev != (c2_cxx_try_block *)0x0) {
    pcVar1 = prev->trymap_next;
  }
  while ((pcVar1 != (c2_cxx_try_block *)0x0 && ((pcVar1->state_rec->flags & 0x400) != 0))) {
    pcVar1 = pcVar1->trymap_next;
  }
  return pcVar1;
}

