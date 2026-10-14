int __fastcall inline_formal_substitutable(c2_tuple *t,c2_operand *actual)

{
  c2_tuple *def;
  c2_tuple *end;
  int iVar1;
  uint uVar2;
  c2_operand *local_4;
  
  uVar2 = 1 << (actual->kind & 0x1f);
  if ((uVar2 & 0x18) != 0) {
    return 1;
  }
  local_4 = (c2_operand *)t;
  end = find_next_use_of_dst(t,&local_4);
  if ((uVar2 & 0x380) == 0) {
    if (actual->kind == '\x02') {
      iVar1 = inline_range_may_write(actual,&t->next,end);
      return (uint)(iVar1 == 0);
    }
    if (((uVar2 & 6) != 0) && (def = actual->sym->def, def != (c2_tuple *)0x0)) {
      iVar1 = inline_def_tree_reads_written(def,&t->next,end);
      return (uint)(iVar1 == 0);
    }
  }
  else if (((1 << (local_4->kind & 0x1f) & 0xffeU) == 0) ||
          ((*(uint16_t *)&local_4->flags & 0x20) == 0)) {
    return 1;
  }
  return 0;
}

