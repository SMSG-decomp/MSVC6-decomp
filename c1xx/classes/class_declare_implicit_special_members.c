void __cdecl class_declare_implicit_special_members(c1_symbol *cls)

{
  c1_class_record *pcVar1;
  c1_symbol *cls_00;
  byte bVar2;
  c1_u8 *state_cursor;
  int iVar3;
  c1_u8 *pcVar4;
  int local_28;
  c1_u8 special_states [35];
  
  cls_00 = cls;
  pcVar4 = special_states;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    pcVar4[0] = '\0';
    pcVar4[1] = '\0';
    pcVar4[2] = '\0';
    pcVar4[3] = '\0';
    pcVar4 = pcVar4 + 4;
  }
  pcVar4[0] = '\0';
  pcVar4[1] = '\0';
  pcVar4[2] = '\0';
  state_cursor = special_states + 7;
  do {
    *state_cursor = '\x01';
    state_cursor[6] = '\x01';
    state_cursor[4] = '\x01';
    state_cursor = state_cursor + 7;
  } while (state_cursor <= special_states + 0x1c);
  class_merge_base_special_member_states(cls,special_states);
  class_merge_member_special_member_states(cls_00,special_states);
  class_warn_multiple_special_members(cls_00,special_states,(int *)&cls,&local_28);
  pcVar1 = (cls_00->detail).cls;
  if ((pcVar1->layout_flags3a & 0xc0) != 0) {
    special_states[8] = '\x01';
    special_states[0xf] = '\x01';
    special_states[0x16] = '\x01';
    pcVar1->layout_flags3c = pcVar1->layout_flags3c & 0xfe;
  }
  if (((((int)cls < 1) && (special_states[8] == '\0')) && (special_states[0xf] == '\0')) &&
     ((g_class_def_stack[g_class_depth].flags & 4) == 0)) {
    bVar2 = 1;
  }
  else {
    bVar2 = 0;
  }
  ((cls_00->detail).cls)->layout_flags3c = ((cls_00->detail).cls)->layout_flags3c & (bVar2 | 0xfe);
  class_declare_implicit_member_by_state(cls_00,special_states,1,0x1fe,cls == (c1_symbol *)0x0);
  class_declare_implicit_member_by_state(cls_00,special_states,2,0x1ff,'\x01');
  class_declare_implicit_member_by_state(cls_00,special_states,3,0x200,'\x01');
  class_declare_implicit_member_by_state(cls_00,special_states,4,0x201,'\x01');
  if (((cls == (c1_symbol *)0x0) && ((((cls_00->detail).cls)->implicit_state41 & 2) == 0)) &&
     ((((cls_00->detail).cls)->implicit_state42 & 2) == 0)) {
    diag_warning(4,0x262,cls_00->type,cls_00);
    return;
  }
  if ((cls_00->flags2 & 4) == 0) {
    tmpl_instantiate_if_needed(cls_00);
  }
  if (((((cls_00->detail).cls)->implicit_state41 & 0x10) == 0) &&
     ((((cls_00->detail).cls)->implicit_state43 & 0x10) == 0)) {
    diag_warning(4,0x20f,cls_00->type,cls_00);
  }
  return;
}

