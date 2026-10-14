c1_vtable_record * __cdecl class_first_vbtable_record(c1_symbol *cls)

{
  return *((cls->detail).cls)->vbtables->data;
}

