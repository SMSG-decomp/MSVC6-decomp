void __fastcall emit_strip_eh_pseudo_ops(c2_function *fn)

{
  c2_tuple *pcVar1;
  c2_tuple *pcVar2;
  c2_tuple *t;
  
  pcVar1 = fn->cfg->last->end;
  t = fn->cfg->first->head->next;
  while (t != pcVar1) {
    pcVar2 = t->next;
    switch(t->op) {
    case 0x18b:
    case 0x192:
    case 0x193:
    case 0x194:
    case 0x195:
    case 0x196:
    case 0x197:
    case 0x198:
    case 0x19a:
      tuple_unlink_free(t);
      break;
    case 0x18e:
      switch_free(t);
    }
    t = pcVar2;
  }
  return;
}

