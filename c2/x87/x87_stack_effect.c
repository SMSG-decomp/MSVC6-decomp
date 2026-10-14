int __fastcall x87_stack_effect(c2_tuple *t)

{
  uint32_t uVar1;
  c2_operand *pcVar2;
  int iVar3;
  
  if (((t->kind != '\x0e') && (uVar1 = t->op, uVar1 != 0x19e)) && (uVar1 != 0x166)) {
    if (((t->type & 0xf000) == 0x4000) || (uVar1 == 0x5b)) {
      switch(uVar1) {
      case 0x4b:
      case 0x4c:
      case 0x4d:
      case 0x4e:
      case 0x4f:
      case 0x50:
      case 0x53:
      case 0x5b:
      case 0x5d:
      case 99:
      case 0x69:
      case 0x86:
      case 0x91:
      case 0x92:
      case 0xd2:
        return -1;
      case 0x56:
      case 0x60:
      case 100:
      case 0x7f:
      case 0x80:
      case 0x81:
      case 0x82:
      case 0x83:
      case 0x84:
      case 0x88:
      case 0x90:
      case 0x94:
        return 1;
      case 0x5e:
      case 0xd3:
        return -2;
      }
    }
    return 0;
  }
  pcVar2 = t->dst;
  iVar3 = 0;
  while( true ) {
    if (pcVar2 == (c2_operand *)0x0) {
      for (pcVar2 = t->src; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
        if ((pcVar2->kind == '\x01') && ((pcVar2->type & 0xf000) == 0x4000)) {
          iVar3 = iVar3 + -1;
        }
      }
      return iVar3;
    }
    if ((pcVar2->kind == '\x01') && ((pcVar2->type & 0xf000) == 0x4000)) break;
    pcVar2 = pcVar2->next;
  }
  iVar3 = x87_stack_effect_part(t,pcVar2,1,'\x01');
  return iVar3;
}

