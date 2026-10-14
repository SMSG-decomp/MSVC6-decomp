int __cdecl debug_type_record_pointer(c1_type *type,int pointee_index)

{
  ushort uVar1;
  c1_symbol *pcVar2;
  c1_u16 *pcVar3;
  ushort *puVar4;
  c1_type *pcVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  pcVar5 = type;
  puVar4 = g_cv_record_body;
  pcVar3 = &type->code;
  type = (c1_type *)0x0;
  uVar7 = -(uint)((*pcVar3 & 0x80) != 0) & (uint)pcVar5;
  uVar1 = *(ushort *)(uVar7 + 2);
  if ((uVar1 & 8) != 0) {
    pcVar2 = *(c1_symbol **)(uVar7 + 8);
    if (((byte)uVar1 & 0x18) == 0x18) {
      if ((pcVar2->kind & 0x1f) == 0xe) {
        if ((pcVar2->entity & 0xffffff) != 6) {
          sym_new_numbered_3(pcVar2);
          debug_type_index(((pcVar2->x2c).debug_object)->type);
        }
      }
      else {
        debug_type_index(pcVar2->type);
      }
    }
  }
  *puVar4 = 0x1002;
  uVar8 = g_cv_zero_attributes;
  *(int *)(puVar4 + 1) = pointee_index;
  *(uint *)(puVar4 + 3) = uVar8;
  uVar8 = uVar8 & 0xffffff1f;
  *(uint *)(puVar4 + 3) = uVar8;
  if ((uVar1 & 0x20) != 0) {
    *(uint *)(puVar4 + 3) = uVar8 | 0x400;
  }
  if ((uVar1 & 0x40) != 0) {
    *(uint *)(puVar4 + 3) = *(uint *)(puVar4 + 3) | 0x200;
  }
  if ((uVar1 & 0x100) != 0) {
    *(uint *)(puVar4 + 3) = *(uint *)(puVar4 + 3) | 0x1000;
  }
  if ((uVar1 & 8) == 0) {
    *(uint *)(puVar4 + 3) = *(uint *)(puVar4 + 3) & 0xffffffea | 10;
  }
  else {
    pcVar2 = *(c1_symbol **)(uVar7 + 8);
    if ((uVar1 & 0x18) == 8) {
      uVar7 = *(uint *)(puVar4 + 3);
      puVar4[5] = 3;
      puVar4[6] = 0;
      *(undefined1 *)(puVar4 + 7) = 0;
      type = (c1_type *)0x5;
      *(uint *)(puVar4 + 3) = uVar7 & 0xffffffe8 | 8;
    }
    else if ((uVar1 & 0x18) == 0x18) {
      *(uint *)(puVar4 + 3) = *(uint *)(puVar4 + 3) & 0xffffffe4 | 4;
      type = (c1_type *)debug_tag_reference_record((short *)(puVar4 + 5),pcVar2);
    }
  }
  iVar6 = cvserver_emit_type((uint)((int)&type->extra + 2));
  return iVar6;
}

