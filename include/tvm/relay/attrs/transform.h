/*!
 *  Copyright (c) 2018 by Contributors
 * \file tvm/relay/attrs/transform.h
 * \brief Transform operators.
 */
#ifndef TVM_RELAY_ATTRS_TRANSFORM_H_
#define TVM_RELAY_ATTRS_TRANSFORM_H_

#include <tvm/attrs.h>
#include <string>

namespace tvm {
namespace relay {

/*! \brief data type cast */
struct CastAttrs : public tvm::AttrsNode<CastAttrs> {
  DataType dtype;

  TVM_DECLARE_ATTRS(CastAttrs, "relay.attrs.CastAttrs") {
    TVM_ATTR_FIELD(dtype)
        .describe("Target data type");
  }
};  // struct CastAttrs.

/*! \brief Attributes used in expand_dims operators */
struct ExpandDimsAttrs : public tvm::AttrsNode<ExpandDimsAttrs> {
  int axis;
  int num_newaxis;

  TVM_DECLARE_ATTRS(ExpandDimsAttrs, "relay.attrs.ExpandDimsAttrs") {
    TVM_ATTR_FIELD(axis)
        .describe("The axis at which the input array is expanded."
                  "Should lie in range `[-data.ndim - 1, data.ndim]`."
                  "If `axis < 0`, it is the first axis inserted;"
                  "If `axis >= 0`, it is the last axis inserted in Python's negative indexing.");
    TVM_ATTR_FIELD(num_newaxis)
        .describe("Number of axises to be inserted. Should be >= 0.")
        .set_lower_bound(0)
        .set_default(1);
  }
};  // struct ExpandDimsAttrs

/*! \brief Attributes used in concatenate operators */
struct ConcatenateAttrs : public tvm::AttrsNode<ConcatenateAttrs> {
  int axis;
  TVM_DECLARE_ATTRS(ConcatenateAttrs, "relay.attrs.ConcatenateAttrs") {
    TVM_ATTR_FIELD(axis)
        .describe("The axis at which the input arrays are concatenated."
                  "Should lie in range `[-ndim, ndim)`.")
        .set_default(0);
  }
};  // struct ConcatenateAttrs

/*! \brief Attributes used in transpose operators */
struct TransposeAttrs : public tvm::AttrsNode<TransposeAttrs> {
  Array<Integer> axes;
  TVM_DECLARE_ATTRS(TransposeAttrs, "relay.attrs.TransposeAttrs") {
    TVM_ATTR_FIELD(axes)
        .describe("The target axes order, reverse order if not specified.");
  }
};  // struct TransposeAttrs

/*! \brief Attributes used in reshape operators */
struct ReshapeAttrs : public tvm::AttrsNode<ReshapeAttrs> {
  Array<IndexExpr> newshape;
  TVM_DECLARE_ATTRS(ReshapeAttrs, "relay.attrs.ReshapeAttrs") {
    TVM_ATTR_FIELD(newshape)
        .describe("The new shape. Should be compatible with the original shape.");
  }
};  // struct ReshapeAttrs

struct TakeAttrs : public tvm::AttrsNode<TakeAttrs> {
  Integer axis;

  TVM_DECLARE_ATTRS(TakeAttrs, "relay.attrs.TakeAttrs") {
    TVM_ATTR_FIELD(axis).set_default(NullValue<Integer>())
        .describe("The axis over which to select values.");
  }
};

/*! \brief Attributes that specify a tensor */
struct InitOpAttrs : public tvm::AttrsNode<InitOpAttrs> {
  Array<IndexExpr> shape;
  DataType dtype;

  TVM_DECLARE_ATTRS(InitOpAttrs, "relay.attrs.InitOpAttrs") {
    TVM_ATTR_FIELD(shape)
      .describe("Target shape.");
    TVM_ATTR_FIELD(dtype)
      .describe("Target data type.")
      .set_default(NullValue<DataType>());
  }
};  // struct InitOpAttrs

/*! \brief Attributes used in squeeze operators */
struct SqueezeAttrs : public tvm::AttrsNode<SqueezeAttrs> {
  Array<IndexExpr> axes;

  TVM_DECLARE_ATTRS(SqueezeAttrs, "relay.attrs.SqueezeAttrs") {
    TVM_ATTR_FIELD(axes)
        .describe("The axes to squeeze in the input tensor."
                  "If `axes = []`, all axis of dimension 1 get squeezed;"
                  "Else, the dimension in axes get squeezed."
                  "It is an error if an axes does not has dimension 1.")
        .set_default(Array<IndexExpr>({}));
  }
};  // struct SqueezeAttrs

}  // namespace relay
}  // namespace tvm
#endif  // TVM_RELAY_ATTRS_TRANSFORM_H_
