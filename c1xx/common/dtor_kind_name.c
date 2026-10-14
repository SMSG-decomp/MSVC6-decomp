void * __cdecl dtor_kind_name(int kind)

{
  switch(kind) {
  case 1:
  case 3:
    return g_name_dtor;
  case 2:
    return g_name_vbase_dtor;
  case 4:
    return g_name_scalar_deleting_dtor;
  case 5:
    return g_name_vector_deleting_dtor;
  default:
    return (void *)0x0;
  }
}

