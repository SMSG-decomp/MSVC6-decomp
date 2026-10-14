int __cdecl type_modifier_bits_match(c1_u16 flags1,c1_u16 flags2)

{
  if (g_opt_Zg != '\0') {
    return 1;
  }
  if (((flags1 ^ flags2) & 0x18) == 0) {
    return (uint)(((flags1 ^ flags2) & 7) == 0);
  }
  return 0;
}

