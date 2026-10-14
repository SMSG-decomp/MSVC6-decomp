void __cdecl class_conversion_functions_begin(c1_conversion_type_iter *iter,c1_symbol *cls)

{
  if ((cls->flags2 & 4) == 0) {
    tmpl_instantiate_if_needed(cls);
  }
  if (((cls->detail).cls)->conversion_functions != (c1_symbol_vector *)0x0) {
    iter->types = ((cls->detail).cls)->repeated_conversion_types;
    vector_iterator_init(&iter->functions,((cls->detail).cls)->conversion_functions);
    return;
  }
  iter->types = (void *)0x0;
  return;
}

