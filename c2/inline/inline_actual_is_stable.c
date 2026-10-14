int __fastcall inline_actual_is_stable(c2_tuple *arg,c2_tuple **first,c2_tuple *end)

{
  c2_operand *op;
  c2_tuple *t;
  uint uVar1;
  int iVar2;
  
  op = arg->src;
  uVar1 = 1 << (op->kind & 0x1f);
  if (((uVar1 & 0x380) == 0) && ((uVar1 & 0x18) == 0)) {
    if (op->kind == 2) {
      iVar2 = inline_range_may_write(op,&arg->next,(c2_tuple *)0x0);
      if (iVar2 != 0) {
        return 0;
      }
      iVar2 = inline_range_may_write(op,first,end);
    }
    else {
      if ((uVar1 & 6) == 0) {
        return 0;
      }
      t = op->sym->def;
      if (t == (c2_tuple *)0x0) {
        return 0;
      }
      iVar2 = inline_tree_reads_written(t,(c2_tuple *)0x0);
      if (iVar2 != 0) {
        return 0;
      }
      iVar2 = inline_def_tree_reads_written(t,first,end);
    }
    if (iVar2 != 0) {
      return 0;
    }
  }
  return 1;
}

