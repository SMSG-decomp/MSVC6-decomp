uint32_t __fastcall function_stores_to_stack_symbol(c2_tuple *t)

{
  uint8_t uVar1;
  c2_operand *pcVar2;
  
  while (t != (c2_tuple *)0x0) {
    switch(t->kind) {
    case '\x11':
    case '\x13':
    case '\x18':
    case '\x1a':
      goto LAB_1073a4e9;
    default:
      if (((((t->flags & 1) != 0) && (pcVar2 = t->dst, pcVar2 != (c2_operand *)0x0)) &&
          (pcVar2->kind == '\x02')) &&
         ((((uVar1 = pcVar2->sym->cls, uVar1 == '\x03' || (uVar1 == '\x04')) ||
           ((uVar1 != '\x05' && (uVar1 == '\x06')))) && (uVar1 != '\x05')))) {
        return 1;
      }
      t = t->next;
    }
  }
LAB_1073a4e9:
  return 0;
}

