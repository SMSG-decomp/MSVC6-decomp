c2_tuple * __fastcall find_next_reg_writer(c2_tuple *t)

{
  uint uVar1;
  c2_operand *pcVar2;
  int iVar3;
  
  iVar3 = 0;
  if (t->op != 0x10) {
    t = t->next;
  }
  do {
    if (t == (c2_tuple *)0x0) {
      return (c2_tuple *)0x0;
    }
    if ((((t->flags & 1) != 0) && (uVar1 = t->op, uVar1 != 0)) && (uVar1 < 0x144)) {
      if ((g_x86_op_flags[uVar1] & 4) != 0) {
        return t;
      }
      if ((g_x86_op_flags[uVar1] & 2) != 0) {
        return (c2_tuple *)0x0;
      }
      if (uVar1 == 0x10) {
        pcVar2 = t->src;
        if (pcVar2->kind != '\x04') {
          return (c2_tuple *)0x0;
        }
        if (pcVar2->op != 0x154) {
          return (c2_tuple *)0x0;
        }
        iVar3 = iVar3 + 1;
        t = *(c2_tuple **)((int)&pcVar2->sym->u30 + 2);
        if (3 < iVar3) {
          return t;
        }
      }
    }
    t = t->next;
  } while( true );
}

