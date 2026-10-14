c2_tuple * __fastcall jump_opt_restart_point(c2_tuple *t)

{
  c2_tuple *pcVar1;
  c2_tuple *pcVar2;
  
  pcVar2 = t;
  if (t != (c2_tuple *)0x0) {
    for (pcVar1 = t->prev;
        ((pcVar2 = t, pcVar1 != (c2_tuple *)0x0 && (pcVar2 = pcVar1, pcVar1->kind != '\x11')) &&
        (pcVar1->kind != '\x1a')); pcVar1 = pcVar1->prev) {
    }
  }
  return pcVar2;
}

