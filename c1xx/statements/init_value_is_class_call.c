uint __cdecl init_value_is_class_call(c1_node *value)

{
  char cVar1;
  c1_type *pcVar2;
  byte bVar3;
  ushort uVar4;
  int iVar5;
  
  iVar5 = 0;
LAB_1046fa05:
  do {
    switch(value->op) {
    case '.':
    case '`':
    case 'd':
      value = value->left;
      break;
    default:
      goto switchD_1046fa19_caseD_2f;
    case '7':
      value = value->right;
      if (iVar5 == 0) goto LAB_1046fa05;
      iVar5 = iVar5 + 1;
      break;
    case '=':
      if (iVar5 == 0) {
        value = value->left;
        iVar5 = 2;
        goto LAB_1046fa2c;
      }
      goto switchD_1046fa19_caseD_2f;
    case 'e':
    case 0x9c:
      goto switchD_1046fa19_caseD_65;
    case 'p':
      if (iVar5 != 0) {
        pcVar2 = type_function_return(*(c1_type **)((int)value->left + 4));
        bVar3 = (byte)pcVar2->code;
        cVar1 = -((char)bVar3 >> 7);
        value = (c1_node *)CONCAT31((int3)((uint)pcVar2 >> 8),cVar1);
        if (((cVar1 != '\0') && ((bVar3 & 0x8f) == 0x80)) ||
           ((cVar1 != '\0' && ((uVar4 = pcVar2->code & 0x8f, uVar4 == 0x86 || (uVar4 == 0x82))))))
        goto switchD_1046fa19_caseD_2f;
      }
switchD_1046fa19_caseD_65:
      return CONCAT31((int3)((uint)value >> 8),1);
    }
    if (iVar5 != 0) {
LAB_1046fa2c:
      iVar5 = iVar5 + -1;
      if (iVar5 == 0) {
switchD_1046fa19_caseD_2f:
        return (uint)value & 0xffffff00;
      }
    }
  } while( true );
}

