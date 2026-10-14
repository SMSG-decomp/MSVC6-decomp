int __fastcall inline_tree_reads_written(c2_tuple *t,c2_tuple *end)

{
  byte bVar1;
  c2_operand *op;
  c2_tuple *t_00;
  int iVar2;
  
  if (((t->kind == '\x0e') || (t->kind == '\x12')) &&
     (iVar2 = inline_range_has_call_or_memory(t,end), iVar2 != 0)) {
    return 1;
  }
  op = t->src;
  do {
    if (op == (c2_operand *)0x0) {
      return 0;
    }
    bVar1 = op->kind;
    if (((1 << (bVar1 & 0x1f) & 6U) == 0) || (t_00 = op->sym->def, t_00 == (c2_tuple *)0x0)) {
      if ((bVar1 == 2) || (bVar1 == 6)) {
        iVar2 = inline_range_may_write(op,&t->next,end);
        goto joined_r0x107523c8;
      }
    }
    else {
      iVar2 = inline_tree_reads_written(t_00,end);
joined_r0x107523c8:
      if (iVar2 != 0) {
        return 1;
      }
    }
    op = op->next;
  } while( true );
}

