c2_operand * __fastcall tuple_nth_src(c2_tuple *t,uint8_t n)

{
  c2_operand *pcVar1;
  int iVar2;
  
  pcVar1 = t->src;
  if (1 < n) {
    iVar2 = n - 1;
    do {
      pcVar1 = pcVar1->next;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return pcVar1;
}

