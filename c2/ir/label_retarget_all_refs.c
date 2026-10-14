void __fastcall label_retarget_all_refs(c2_tuple *t,c2_node *label)

{
  c2_operand *pcVar1;
  
  pcVar1 = t->dst;
  while (pcVar1 != (c2_operand *)0x0) {
    tuple_retarget((c2_tuple *)pcVar1->rank,label,0);
    pcVar1 = t->dst;
  }
  return;
}

