int __fastcall class_debug_type_in_pdb(c1_symbol *cls)

{
  if ((g_debug_types_in_pdb != '\0') && ((((cls->detail).cls)->flags3f & 8) != 0)) {
    return 1;
  }
  return 0;
}

