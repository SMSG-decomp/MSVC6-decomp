void __cdecl class_merge_member_special_member_states(c1_symbol *cls,c1_u8 *states)

{
  c1_u32 *sym;
  c1_u8 *pcVar1;
  byte bVar2;
  c1_symbol *sub;
  int iVar3;
  c1_sym_link *pcVar4;
  c1_sym_link *pcVar5;
  c1_sym_link *pcVar6;
  
  if ((cls->x28).members == (c1_sym_list *)0x0) {
    pcVar4 = (c1_sym_link *)0x0;
  }
  else {
    pcVar4 = ((cls->x28).members)->head;
  }
  pcVar6 = (c1_sym_link *)0x0;
  if (pcVar4 != (c1_sym_link *)0x0) {
    pcVar6 = pcVar4;
  }
  while (pcVar5 = pcVar6, pcVar5 != (c1_sym_link *)0x0) {
    if ((pcVar4 == (c1_sym_link *)0x0) ||
       (pcVar4 = pcVar4->next, pcVar6 = pcVar4, pcVar4 == (c1_sym_link *)0x0)) {
      pcVar6 = (c1_sym_link *)0x0;
    }
    bVar2 = (byte)pcVar5[-1].position & 0x1f;
    if (((bVar2 == 3) || (bVar2 == 2)) && ((pcVar5[-1].position & 0x1000000) == 0)) {
      sym = &pcVar5[-1].position;
      sub = sym_class_type_of((c1_symbol *)sym);
      iVar3 = sym_is_static_data_member((c1_symbol *)sym);
      if ((iVar3 == 0) && ((pcVar5[1].position & 0x80000000) == 0)) {
        if (sub != (c1_symbol *)0x0) {
          class_check_subobject_special_members(cls,sub,states);
          if ((((sub->detail).cls)->layout_flags3c & 1) == 0) {
            pcVar1 = &((cls->detail).cls)->layout_flags3c;
            *pcVar1 = *pcVar1 & 0xfe;
          }
          bVar2 = ((cls->detail).cls)->layout_flags3b;
          ((cls->detail).cls)->layout_flags3b =
               (((sub->detail).cls)->layout_flags3b ^ bVar2) & 8 ^ bVar2;
        }
        iVar3 = class_member_is_const_or_reference((c1_symbol *)sym);
        if ((char)iVar3 != '\0') {
          states[7] = '\0';
          states[8] = '\x01';
          states[0x15] = '\0';
          states[0x16] = '\x01';
        }
      }
    }
  }
  return;
}

