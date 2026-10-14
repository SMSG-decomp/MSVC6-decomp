uint __fastcall type_calling_convention_bits(ushort *type)

{
  for (; (((byte)*type & 0x8f) == 0x83 || (((byte)*type & 0x83) == 0x81));
      type = *(ushort **)(type + 2)) {
  }
  return type[1] & 0x3e0;
}

