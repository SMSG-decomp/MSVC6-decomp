uint __fastcall decl_dll_linkage_kind(c1_specifier_words *spec)

{
  return ((spec->declspec & 8) >> 3) << 1 | spec->declspec >> 2 & 1;
}

