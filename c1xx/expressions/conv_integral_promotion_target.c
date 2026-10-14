c1_type * __cdecl conv_integral_promotion_target(c1_type *other,c1_node **operand)

{
  ushort uVar1;
  ushort uVar2;
  c1_node *pcVar3;
  byte bVar4;
  char cVar5;
  
  uVar1 = (*operand)->type->code;
  if ((uVar1 & 0x110) == 0) {
    if (((((byte)uVar1 >> 5 & 1) != 0) && (((byte)other->code >> 5 & 1) != 0)) &&
       ((char)(&g_type_rank_table)[uVar1 & 0xf] < (char)(&g_type_rank_table)[other->code & 0xf])) {
      return other;
    }
    return (c1_type *)0x0;
  }
  uVar2 = other->code;
  bVar4 = (byte)uVar2;
  if (((uVar2 & 0x110) == 0) && (-1 < (char)bVar4)) {
    if ((bVar4 >> 5 & 1) == 0) {
      return (c1_type *)((uint)g_type_int & ('\x03' < (char)(&g_type_rank_table)[uVar1 & 0xf]) - 1);
    }
    if ((char)(&g_type_rank_table)[uVar1 & 0xf] < '\x04') {
      pcVar3 = conv_convert_expression('d',g_type_int,*operand,'\x02','\0');
      *operand = pcVar3;
    }
    return other;
  }
  cVar5 = '\x04';
  if (-1 < (char)bVar4) {
    cVar5 = (&g_type_rank_table)[uVar2 & 0xf];
  }
  if ((cVar5 < '\x05') && ((char)(&g_type_rank_table)[uVar1 & 0xf] < '\x04')) {
    return g_type_int;
  }
  if ((char)(&g_type_rank_table)[uVar1 & 0xf] < cVar5) {
    return other;
  }
  if ((uVar1 & 0x100) != 0) {
    return g_type_int;
  }
  return (c1_type *)(~-(uint)((uVar1 & 0xfff) != 0x10) & (uint)g_type_int);
}

