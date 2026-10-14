char __cdecl class_vbase_needs_empty_gap(c1_symbol *vbase,c1_symbol *cls)

{
  byte bVar1;
  char cVar2;
  
  if (((g_class_previous_vbase == (c1_symbol *)0x0) ||
      ((((g_class_previous_vbase->detail).cls)->layout_flags3b & 8) == 0)) ||
     ((((vbase->detail).cls)->layout_flags3b & 4) == 0)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  g_class_previous_vbase = vbase;
  bVar1 = ((cls->detail).cls)->layout_flags3b;
  ((cls->detail).cls)->layout_flags3b = (((vbase->detail).cls)->layout_flags3b ^ bVar1) & 8 ^ bVar1;
  return cVar2;
}

