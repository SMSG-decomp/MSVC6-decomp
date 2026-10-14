c1_u32 __cdecl debug_type_record_modifier(c1_type *type)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  c1_type *type_00;
  c1_u32 cVar4;
  ushort uVar5;
  ushort uVar6;
  
  puVar3 = g_cv_record_body;
  type_00 = (c1_type *)type_strip_modifier_bits((uint *)type);
  cVar4 = debug_type_index(type_00);
  *puVar3 = 0x1001;
  puVar3[3] = (ushort)g_cv_zero_attributes;
  uVar5 = type->flags >> 5 & 1;
  uVar2 = (ushort)g_cv_zero_attributes;
  puVar3[3] = uVar5 | uVar2 & 0xfffe;
  uVar6 = type->flags >> 5 & 2;
  puVar3[3] = uVar6 | uVar5 | uVar2 & 0xfffc;
  uVar1 = type->flags;
  *(c1_u32 *)(puVar3 + 1) = cVar4;
  puVar3[3] = uVar1 >> 5 & 4 | uVar6 | uVar5 | uVar2 & 0xfff8;
  cVar4 = cvserver_emit_type(8);
  type->debug_index = cVar4;
  return cVar4;
}

