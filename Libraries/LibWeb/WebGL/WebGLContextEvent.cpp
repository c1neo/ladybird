/*
 * Copyright (c) 2022, Andreas Kling <andreas@ladybird.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <LibWeb/Bindings/Intrinsics.h>
#include <LibWeb/Bindings/WebGLContextEventPrototype.h>
#include <LibWeb/WebGL/WebGLContextEvent.h>

namespace Web::WebGL {

GC_DEFINE_ALLOCATOR(WebGLContextEvent);

GC::Ref<WebGLContextEvent> WebGLContextEvent::create(JS::Realm& realm, FlyString const& event_name, WebGLContextEventInit const& event_init)
{
    return realm.create<WebGLContextEvent>(realm, event_name, event_init);
}

WebIDL::ExceptionOr<GC::Ref<WebGLContextEvent>> WebGLContextEvent::construct_impl(JS::Realm& realm, FlyString const& event_name, WebGLContextEventInit const& event_init)
{
    return create(realm, event_name, event_init);
}

WebGLContextEvent::WebGLContextEvent(JS::Realm& realm, FlyString const& type, WebGLContextEventInit const& event_init)
    : DOM::Event(realm, type, event_init)
    , m_status_message(event_init.status_message)
{
}

WebGLContextEvent::~WebGLContextEvent() = default;

void WebGLContextEvent::initialize(JS::Realm& realm)
{
    WEB_SET_PROTOTYPE_FOR_INTERFACE(WebGLContextEvent);
    Base::initialize(realm);
}

}
