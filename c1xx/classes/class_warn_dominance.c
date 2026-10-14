void class_warn_dominance(c1_vtable_slot *edi)

{
  ushort *puVar1;
  char cVar2;
  int iVar3;
  c1_vtable_slot *slot;
  int *in_stack_00000010;
  int in_stack_00000014;
  int in_stack_0000001c;
  uint in_stack_00000020;
  undefined2 in_stack_00000024;
  int *in_stack_00000028;
  int in_stack_00000034;
  int in_stack_0000003c;
  int *in_stack_00000044;
  
  diag_warning(2,0xfa);
  do {
    while (*in_stack_00000044 <= in_stack_00000014) {
LAB_10436fc2:
      do {
        iVar3 = vector_iterator_next(&stack0x00000020);
        cVar2 = (char)iVar3;
        in_stack_00000010 = in_stack_00000028;
        while (in_stack_00000028 = in_stack_00000010, cVar2 == '\0') {
          iVar3 = vector_iterator_next((uint *)&stack0x0000002c);
          if ((char)iVar3 == '\0') {
            return;
          }
          in_stack_0000003c = in_stack_00000034;
          in_stack_00000020 = *(uint *)(in_stack_00000034 + 0x14 + in_stack_0000001c * 4);
          in_stack_00000024 = SUB42(edi,0);
          iVar3 = vector_iterator_next(&stack0x00000020);
          in_stack_00000010 = in_stack_00000028;
          cVar2 = (char)iVar3;
        }
      } while (*in_stack_00000010 != 2);
      in_stack_00000014 = 0;
      in_stack_00000044 = in_stack_00000010 + 4;
    }
    slot = (c1_vtable_slot *)(in_stack_00000014 * 0x10 + in_stack_00000010[6]);
    in_stack_00000014 = in_stack_00000014 + 1;
    if (slot == edi) goto LAB_10436fc2;
    if ((slot->flags & 4) == 0) {
      if ((slot->flags & 2) != 0) {
        class_warn_dominance(edi);
        return;
      }
    }
    else {
      puVar1 = (ushort *)slot->member;
      for (; (puVar1 != (ushort *)0x0 && ((int)(short)edi < (int)(uint)*puVar1));
          edi = (c1_vtable_slot *)(uint)(ushort)((short)edi + 1)) {
        diag_error(0xfa);
      }
      class_vtable_slot_take_first_candidate(slot);
      edi = (c1_vtable_slot *)0x0;
    }
  } while( true );
}

