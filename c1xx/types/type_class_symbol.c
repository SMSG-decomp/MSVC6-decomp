c1_symbol * __cdecl type_class_symbol(c1_type *type)

{
  type_classify_class_form(type,(int *)&type);
  return (c1_symbol *)type;
}

