c1_symbol * __cdecl class_declare_table_pointer_member(c1_symbol *cls,int kind)

{
  ushort uVar1;
  c1_class_record *pcVar2;
  void *pvVar3;
  c1_decl_record *pcVar4;
  c1_u8 *params;
  c1_symbol *sym;
  uint alignment;
  uint uVar5;
  uint uVar6;
  c1_type *pcVar7;
  uint uVar8;
  uint uVar9;
  uint offset;
  c1_declarator *d;
  int delta;
  c1_symbol *local_40;
  uint ptr3_extra_word1;
  ushort local_38 [2];
  uint ptr3_mods_position;
  int local_30 [2];
  ushort local_28 [2];
  uint ptr1_extra_word1;
  ushort local_20 [2];
  uint ptr1_mods_position;
  int local_18 [2];
  ushort local_10 [2];
  uint ptr2_extra_word1;
  ushort local_8 [2];
  uint ptr2_mods_position;
  
  d = (c1_declarator *)g_arenas[5].cur;
  g_arenas[5].cur = g_arenas[5].cur + 0x58;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  if (d == (c1_declarator *)0x0) {
    d = (c1_declarator *)0x0;
  }
  else {
    if ((kind == 0) || (pvVar3 = g_name_vbptr, kind == 2)) {
      pvVar3 = g_name_vfptr;
    }
    d->name = pvVar3;
    *(c1_u8 *)((int)d + 0x28) = '\0';
    *(c1_u8 *)((int)d + 0x29) = '\0';
    *(c1_u8 *)((int)d + 0x2a) = '\0';
    *(c1_u8 *)((int)d + 0x2b) = '\0';
    *(c1_u8 *)((int)d + 0x30) = '\x01';
    *(c1_u8 *)((int)d + 0x4c) = '\x02';
    *(c1_u8 *)((int)d + 0x4d) = '\0';
    *(c1_u8 *)((int)d + 0x4e) = '\0';
    *(c1_u8 *)((int)d + 0x4f) = '\0';
    pcVar4 = arena_alloc(g_arenas + 5,0x4c);
    if (pcVar4 == (c1_decl_record *)0x0) {
      *(c1_u8 *)((int)d + 4) = '\0';
      *(c1_u8 *)((int)d + 5) = '\0';
      *(c1_u8 *)((int)d + 6) = '\0';
      *(c1_u8 *)((int)d + 7) = '\0';
      *(int *)((int)d + 0x24) = g_token_position;
    }
    else {
      pcVar4 = decl_record_init_default(pcVar4,d->name,*(c1_overload_set **)((int)d + 0x28));
      *(c1_decl_record **)((int)d + 4) = pcVar4;
      *(int *)((int)d + 0x24) = g_token_position;
    }
  }
  pcVar4 = d->decl;
  d->flags54 = d->flags54 | 0x20;
  d->owner = cls;
  if (kind == 0) {
    local_28[0] = 0;
    ptr1_extra_word1 = 0;
    local_20[0] = 0;
    ptr1_mods_position = 0;
    decl_add_pointer_modifier(pcVar4,local_20,local_28);
    local_18[0] = 0;
    local_18[1] = 0;
    decl_append_array_layer(pcVar4,local_18);
    local_10[0] = 0;
    ptr2_extra_word1 = 0;
    local_8[0] = 0;
    ptr2_mods_position = 0;
    decl_add_pointer_modifier(pcVar4,local_8,local_10);
    params = class_record_new_kind5();
    decl_append_function_layer((int *)pcVar4,params);
    pcVar7 = g_type_void;
  }
  else {
    if (kind != 1) goto LAB_1043b8ca;
    local_40 = (c1_symbol *)((uint)local_40 & 0xffff0000);
    ptr3_extra_word1 = 0;
    local_38[0] = 0;
    ptr3_mods_position = 0;
    decl_add_pointer_modifier(pcVar4,local_38,(ushort *)&local_40);
    local_30[0] = 0;
    local_30[1] = 0;
    decl_append_array_layer(pcVar4,local_30);
    pcVar7 = type_int();
  }
  pcVar4->spec_type = pcVar7;
LAB_1043b8ca:
  decl_finish_declarator(pcVar4);
  decl_process_declaration(d);
  sym = sym_new_from_declarator(d,0xffffffff);
  if (kind == 0) {
    ((cls->detail).cls)->vfptr_member = sym;
  }
  local_40 = sym;
  class_prepend_member(sym);
  alignment = type_size(sym->type);
  if (kind == 0) {
    offset = 0;
  }
  else {
    offset = class_nonvirtual_bases_end(cls);
  }
  uVar5 = class_padding_for_offset(alignment,offset);
  uVar8 = (uint)g_class_def_stack[g_class_depth].alignment;
  delta = ((uVar5 + uVar8 + -1 + alignment) / uVar8) * uVar8;
  class_shift_member_offsets(cls,delta,offset);
  uVar8 = g_pack_stack->top->packing;
  uVar9 = uVar8;
  if (alignment <= uVar8) {
    uVar9 = alignment;
  }
  uVar1 = g_class_def_stack[g_class_depth].alignment;
  uVar6 = (uint)uVar1;
  if ((uVar1 <= (ushort)uVar9) && (uVar6 = uVar8, alignment <= uVar8)) {
    uVar6 = alignment;
  }
  g_class_def_stack[g_class_depth].alignment = (c1_u16)uVar6;
  (local_40->detail).cls = (c1_class_record *)(offset + uVar5);
  pcVar2 = (cls->detail).cls;
  if (kind != 0) {
    pcVar2->vbptr_offset = (int)(offset + uVar5);
    ((cls->detail).cls)->layout_flags3a = ((cls->detail).cls)->layout_flags3a | 0x80;
    return local_40;
  }
  pcVar2->vbptr_offset = pcVar2->vbptr_offset + delta;
  ((cls->detail).cls)->layout_flags3a = ((cls->detail).cls)->layout_flags3a | 0x40;
  return local_40;
}

