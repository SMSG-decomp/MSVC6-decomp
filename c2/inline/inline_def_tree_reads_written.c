int __fastcall inline_def_tree_reads_written(c2_tuple *def,c2_tuple **first,c2_tuple *end)

{
  byte bVar1;
  c2_operand *op;
  c2_tuple *def_00;
  int iVar2;
  
  if (((def->kind == '\x0e') || (def->kind == '\x12')) &&
     (iVar2 = inline_range_has_call_or_memory((c2_tuple *)first,end), iVar2 != 0)) {
    return 1;
  }
  op = def->src;
  do {
    if (op == (c2_operand *)0x0) {
      return 0;
    }
    bVar1 = op->kind;
    if (((1 << (bVar1 & 0x1f) & 6U) == 0) || (def_00 = op->sym->def, def_00 == (c2_tuple *)0x0)) {
      if ((bVar1 == 2) || (bVar1 == 6)) {
        iVar2 = inline_range_may_write(op,first,end);
        goto joined_r0x10753116;
      }
    }
    else {
      iVar2 = inline_def_tree_reads_written(def_00,first,end);
joined_r0x10753116:
      if (iVar2 != 0) {
        return 1;
      }
    }
    op = op->next;
  } while( true );
}

