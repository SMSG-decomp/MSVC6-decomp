c1_type * __cdecl conv_arithmetic_result_type(c1_type *type,c1_node **other)

{
  ushort uVar1;
  ushort uVar2;
  byte bVar3;
  char cVar4;
  c1_node *pcVar5;
  uint uVar6;
  
  uVar1 = (*other)->type->code;
  uVar6 = (uint)uVar1;
  if ((uVar1 & 0x110) == 0) {
    if (((((byte)uVar1 >> 5 & 1) != 0) && (((byte)type->code >> 5 & 1) != 0)) &&
       ((char)(&g_type_rank_table)[uVar6 & 0xf] < (char)(&g_type_rank_table)[type->code & 0xf])) {
      return type;
    }
    return (c1_type *)0x0;
  }
  uVar2 = type->code;
  bVar3 = (byte)uVar2;
  if (((uVar2 & 0x110) == 0) && (-1 < (char)bVar3)) {
    if ((bVar3 >> 5 & 1) != 0) {
      if ((char)(&g_type_rank_table)[uVar6 & 0xf] < '\x04') {
        pcVar5 = conv_convert_to_type('d',g_type_int,*other);
        *other = pcVar5;
      }
      return type;
    }
    return (c1_type *)(('\x03' < (char)(&g_type_rank_table)[uVar6 & 0xf]) - 1 & (uint)g_type_int);
  }
  cVar4 = '\x04';
  if (-1 < (char)bVar3) {
    cVar4 = (&g_type_rank_table)[uVar2 & 0xf];
  }
  if ((cVar4 < '\x05') && ((char)(&g_type_rank_table)[uVar6 & 0xf] < '\x04')) {
    return g_type_int;
  }
  if ((char)(&g_type_rank_table)[uVar6 & 0xf] < cVar4) {
    return type;
  }
  return (c1_type *)(-(uint)((uVar1 & 0x100) != 0) & (uint)g_type_int);
}

