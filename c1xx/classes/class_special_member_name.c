void * __cdecl class_special_member_name(int kind)

{
  switch(kind) {
  case 1:
  case 2:
    return g_name_ctor;
  case 3:
    return g_name_operator_assign;
  case 4:
    return g_name_dtor;
  case 5:
    return g_name_vbase_dtor;
  case 6:
    return g_name_scalar_deleting_dtor;
  case 7:
    return g_name_vector_deleting_dtor;
  case 8:
    return g_name_copy_ctor_closure;
  case 9:
    return g_name_local_vftable_ctor_closure;
  case 10:
    return g_name_default_ctor_closure;
  case 0xb:
    return g_name_vector_ctor_iterator;
  case 0xc:
    return g_name_vector_vbase_ctor_iterator;
  case 0xd:
    return g_name_vector_dtor_iterator;
  case 0xe:
    return g_name_eh_vector_ctor_iterator;
  case 0xf:
    return g_name_eh_vector_vbase_ctor_iterator;
  case 0x10:
    return g_name_eh_vector_dtor_iterator;
  default:
    return (void *)0x0;
  }
}

