ushort __cdecl debug_member_field_attributes(c1_symbol *member)

{
  return member->flags2 & 0xff03 | (ushort)g_cv_zero_attributes & 0xfffc;
}

