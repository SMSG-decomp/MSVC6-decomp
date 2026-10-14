ushort __cdecl tmpl_param_type_id_matches(c1_type *type,int param_id)

{
  if (((short)param_id != 0) && ((short)param_id != *(short *)&type->extra)) {
    return 0;
  }
  return *(ushort *)&type->extra;
}

