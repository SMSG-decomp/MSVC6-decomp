int __fastcall propagation_def_use_eligible(c2_tuple *def,c2_tuple *t)

{
  c2_block *pcVar1;
  c2_block *pcVar2;
  int iVar3;
  
  pcVar1 = (def->u14).block;
  pcVar2 = (t->u14).block;
  if (pcVar1 == pcVar2) {
    for (; (def != (c2_tuple *)0x0 && (def->kind != '\x19')); def = def->next) {
      if (def == t) {
        return 1;
      }
    }
  }
  else {
    iVar3 = bitvec_test(pcVar2->dominators,(int)pcVar1->rpo);
    if ((iVar3 != 0) && (pcVar1->loop == pcVar2->loop)) {
      return 1;
    }
  }
  return 0;
}

