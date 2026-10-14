void __fastcall sizeopt_mul_of_extends(c2_tuple *t)

{
  ushort uVar1;
  ushort uVar2;
  c2_operand *pcVar3;
  c2_tuple *t_00;
  c2_tuple *t_01;
  bool bVar4;
  
  pcVar3 = t->src;
  if ((((((1 << (pcVar3->kind & 0x1f) & 6U) != 0) &&
        (t_00 = pcVar3->sym->def, t_00 != (c2_tuple *)0x0)) &&
       ((1 << (pcVar3->next->kind & 0x1f) & 6U) != 0)) &&
      ((((t_01 = pcVar3->next->sym->def, t_01 != (c2_tuple *)0x0 && (t_00->op == 0x15f)) &&
        (((t_00->type & 0xfff) == 8 &&
         ((uVar1 = t_00->src->type, (1 << (byte)(uVar1 >> 0xc) & 0xeU) != 0 &&
          ((uVar1 & 0xfff) == 4)))))) && (t_01->op == 0x15f)))) &&
     (((((t_01->type & 0xfff) == 8 &&
        (uVar2 = t_01->src->type, (1 << (byte)(uVar2 >> 0xc) & 0xeU) != 0)) &&
       ((uVar2 & 0xfff) == 4)) &&
      ((bVar4 = (t->type & 0xf000) == 0x1000, bVar4 == ((uVar1 & 0xf000) == 0x1000) &&
       (bVar4 == ((uVar2 & 0xf000) == 0x1000))))))) {
    tuple_replace_src(t,t->src,t_00->src);
    tuple_replace_src(t,t->src->next,t_01->src);
    tuple_unlink_free(t_00);
    tuple_unlink_free(t_01);
  }
  return;
}

