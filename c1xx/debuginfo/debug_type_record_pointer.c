int __cdecl debug_type_record_pointer(c1_type *type,uint target_index)

{
  ushort uVar1;
  c1_symbol *pcVar2;
  uint uVar3;
  c1_u16 *pcVar4;
  c1_type *pcVar5;
  int iVar6;
  ushort *puVar7;
  ushort uVar8;
  int local_4;
  ushort *body;
  
  pcVar5 = type;
  body = g_cv_record_body;
  pcVar4 = &type->code;
  type._0_2_ = 0;
  puVar7 = (ushort *)(-(uint)((*pcVar4 & 0x80) != 0) & (uint)pcVar5);
  uVar1 = puVar7[1];
  uVar8 = *puVar7 & 0x8f;
  if ((uVar8 == 0x8a) || (uVar8 == 0x8e)) {
    local_4 = debug_type_record_class_forward(*(c1_symbol **)(puVar7 + 4));
  }
  if (((uVar1 & 8) != 0) && (pcVar2 = *(c1_symbol **)(puVar7 + 4), ((byte)uVar1 & 0x18) == 0x18)) {
    if ((pcVar2->kind & 0x1f) == 0xe) {
      if ((pcVar2->entity & 0xffffff) != 6) {
        sym_new_segment_function(pcVar2);
        debug_type_index(((pcVar2->tail).seg_helper)->type);
      }
    }
    else {
      debug_type_index(pcVar2->type);
    }
  }
  *body = 0x1002;
  uVar3 = g_cv_zero_attributes;
  *(uint *)(body + 3) = g_cv_zero_attributes;
  *(uint *)(body + 1) = target_index;
  if (uVar8 == 0x80) {
    *(uint *)(body + 3) = uVar3 & 0xffffff3f | 0x20;
  }
  else if ((uVar8 == 0x8a) || (uVar8 == 0x8e)) {
    body[7] = 0;
    type._0_2_ = 6;
    *(uint *)(body + 3) = ((uVar8 != 0x8a) + 2) * 0x20 | *(uint *)(body + 3) & 0xffffff1f;
    *(int *)(body + 5) = local_4;
  }
  else {
    *(uint *)(body + 3) = *(uint *)(body + 3) & 0xffffff1f;
  }
  if ((uVar1 & 0x20) != 0) {
    *(uint *)(body + 3) = *(uint *)(body + 3) | 0x400;
  }
  if ((uVar1 & 0x40) != 0) {
    *(uint *)(body + 3) = *(uint *)(body + 3) | 0x200;
  }
  if ((uVar1 & 0x100) != 0) {
    *(uint *)(body + 3) = *(uint *)(body + 3) | 0x1000;
  }
  if ((uVar1 & 8) == 0) {
    *(uint *)(body + 3) = *(uint *)(body + 3) & 0xffffffea | 10;
  }
  else {
    pcVar2 = *(c1_symbol **)(puVar7 + 4);
    if ((uVar1 & 0x18) == 8) {
      uVar3 = *(uint *)(body + 3);
      body[5] = 3;
      body[6] = 0;
      *(undefined1 *)(body + 7) = 0;
      type._0_2_ = 5;
      *(uint *)(body + 3) = uVar3 & 0xffffffe8 | 8;
    }
    else if ((uVar1 & 0x18) == 0x18) {
      *(uint *)(body + 3) = *(uint *)(body + 3) & 0xffffffe4 | 4;
      iVar6 = debug_tag_reference_record((short *)(body + 5),pcVar2);
      type._0_2_ = (short)iVar6;
    }
  }
  iVar6 = cvserver_emit_type((short)type + 10);
  return iVar6;
}

