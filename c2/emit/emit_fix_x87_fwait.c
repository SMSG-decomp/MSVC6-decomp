void __fastcall emit_fix_x87_fwait(c2_function *fn)

{
  c2_tuple *pcVar1;
  c2_tuple *fdiv;
  
  if ((fn->flags & 8) != 0) {
    fdiv = fn->cfg->first->head;
    while (fdiv != (c2_tuple *)0x0) {
      pcVar1 = fdiv->next;
      switch(fdiv->op) {
      case 0x49:
      case 0x4a:
      case 0x4f:
      case 0x50:
      case 0x54:
      case 0x55:
      case 0x86:
      case 0x87:
      case 0x88:
      case 0xd4:
        insert_fdiv_bug_check(fdiv,fn);
      }
      fdiv = pcVar1;
    }
  }
  return;
}

