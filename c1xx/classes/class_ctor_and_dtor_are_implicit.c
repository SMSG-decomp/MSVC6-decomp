char __cdecl class_ctor_and_dtor_are_implicit(c1_symbol *cls)

{
  c1_class_record *pcVar1;
  
  pcVar1 = (cls->detail).cls;
  if ((((pcVar1->implicit_state41 & 2) != 0) || ((pcVar1->implicit_state42 & 2) != 0)) &&
     (((pcVar1->implicit_state41 & 0x10) != 0 || ((pcVar1->implicit_state42 & 0x10) != 0)))) {
    return '\x01';
  }
  return '\0';
}

