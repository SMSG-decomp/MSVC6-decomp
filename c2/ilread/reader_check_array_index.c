void __fastcall reader_check_array_index(c2_tuple *t)

{
  c2_symbol *pcVar1;
  c2_tuple *t_00;
  c2_operand *t_01;
  uint uVar2;
  
  while( true ) {
    if ((((c2_operand *)t)->flags9 & 1) != 0) {
      t = (c2_tuple *)((c2_operand *)t)->tag;
    }
    uVar2 = 1 << (((c2_operand *)t)->kind & 0x1f);
    if (((uVar2 & 0xffe) == 0) || ((uVar2 & 6) == 0)) {
      return;
    }
    pcVar1 = ((c2_operand *)t)->sym;
    t_00 = pcVar1->def;
    if (t_00 == (c2_tuple *)0x0) {
      return;
    }
    if ((t_00->op == 0x16d) && (uVar2 = (pcVar1->u30).local_number, (uVar2 & 1) != 0)) {
      reader_discard_value(t_00);
      (pcVar1->u30).local_number = uVar2 & 0xfffffffe;
    }
    if (t_00->op < 0x16d) break;
    if (0x16e < t_00->op) {
      return;
    }
    t_01 = t_00->src;
    reader_check_array_index((c2_tuple *)t_01);
    t = (c2_tuple *)t_01->next;
  }
  return;
}

